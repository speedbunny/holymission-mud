

/* monster */

#define CLEANUP
#define HEAL_INTERVAL    30              /* in seconds */
#define HEAL_FACTOR       2           /* multiplied by CON or INT in HP/SP */
#define SPELL_MASTER      "/spells/master"
#define ABILITY_MASTER    "/abilities/master"

#include "/sys/living.h"

#if 1
#include "/obj/monsoul.c"       /*  only needed for possess ...  */
#endif

#define MAX_HUNTED  5           // how much hunted do i remember (max)

/* USERDOC:
general
This file is a general purpose monster. Generally defined functions:
set_name, set_alias, set_alt_name, set_short, set_long.

Ps: Most functions are explained now, orry but throughout the amount 
    of time this recoding needs, the variables will be explained later :*) 
                                                                     */

string short_desc, long_desc, alias, alt_name;
int move_at_reset,aggressive,no_ears;
string ownenv;
object poisoner;
status healing;
int healing_time;
int prevent_poison;
string *chat_head;          /* Vector with all chat strings. */
int chat_chance;
string *a_chat_head;     /* Vector with all a_chat strings. */
int a_chat_chance;
object talk_ob;
string talk_func;          /* Vector of functions. */
string *talk_match;     /* Vector of strings. */
string talk_type;          /* Vector of types. */
string the_text;
int have_text;
int heart_beat_stat;
int no_steal;              /* if 1, no stealing allowed */
object dead_ob;
object init_ob;
object my_env;         
int random_pick;
mixed has_bag;        /* for intelligent picking monsters */
int spell_chance, max_spell_dam;
string spell_mess1, spell_mess2;
object me,tamer;
object create_room;
int trapped;
int peaced;
int chance_sum;
mixed *local_spells;

object *hunted;                // who do i hunt

/* prototypes */

int update_hp();
void random_move();
mixed test_match(string str);
void pick_any_obj();
int chk_attack(object food);
void init_command(string cmd);
private int handle_concentration( object victim );
private void start_heart_beat();
private void stop_heart_beat();

object present_hunted( object env );
void   add_hunted( object who );
object *get_hunted( );
void   empty_hunted( );

void reset(int arg)
{
    ::reset(arg);
    if (!arg) 
    {
      is_npc = 1;
      healing_time = time(); 
      heart_beat_stat = 0;
      peaced = 0;
      enable_commands();
      hunted = ({});
#if 1
        add_action("xx","n");
        add_action("xx","s");
        add_action("xx","e");
        add_action("xx","w");
        add_action("xx","nw");
        add_action("xx","ne");
        add_action("xx","sw");
        add_action("xx","se");
        add_action("xx","u");
        add_action("xx","d");
#endif 
          me = this_object();
          create_room = environment(me);
#if 1
          sreset(arg);
#endif
    }
    if (move_at_reset)
             random_move();
}

/* USERDOC:
random_move
Format: random_move()
See also: set_whimpy, set_trapped, query_trapped.
This function randomly moves the monster. It checks the exits available in the
room, and if it can't find any it will use "north", "south", "east" and "west".
*/

void random_move() 
{
    string *dirs;

    if ( trapped )                         
             return;

    if(environment() &&
      (dirs=(string *)funcall(call,environment(),"query_room","dest_dir"))) 
    {
            if(sizeof(dirs)/2) 
       {
               last_cmd=dirs[random(sizeof(dirs)/2)*2+1];
               command(last_cmd);
            }
    } 
    else 
    {
            switch(random(4)) 
       {
               case 0:last_cmd="north"; break;
               case 1:last_cmd="south"; break;
               case 2:last_cmd="east"; break;
               case 3:last_cmd="west"; break;
               default: last_cmd="";
            }  
            command(last_cmd);
    }
}

/*
   Function: chk_invis
   This function is like the is_invis_for function in the living.
   It checks out is the other living is invis for the checker.
                                                                    */
varargs int chk_invis(object chk, object who)
{
   if (!who) 
        who = this_object();
   return (funcall(call,who,"is_invis_for",chk) ? 1 : 0);
}

/* see under man short */
mixed short() 
{
    return((!this_player() || chk_invis(this_player())) ? 0 : short_desc);
}

/* see under man long */
void long() 
{
    printf("%s%s", long_desc, tell_health());
}

/* see under man id */
int id(string str)
{
    return (str==name || str==alias || str==real_race || str==alt_name);
}

object looking_for_someone_to_attack(object my_env)
{
    object vic;

    if( !my_env ) return 0;
    if ( peaced ) return( 0 );
   
    vic = first_inventory(my_env);
    while (vic)
    {
        if ( vic != this_object() && !chk_invis(me,vic) && chk_attack(vic) 
             && vic != tamer )
        {
            return vic;
        }
        vic = next_inventory(vic);
    }
    return 0; 
}

/*
   Function: heart_beat
   This function is called all 2 seconds from the parser if the living
   has its heart_beat switched on. Players ever have their heart_beat
   on. To save time a monster switches only the heart_beat on when
   someone is in its environment. When not the heartbeat is set to 0. 
                                                                      */

void heart_beat( )
{
    int c, div, count, i, achk, sec_att, mw;
    object argh, vic, tmp;

    age += 1;
    my_env = environment();
    if(hit_point < max_hp) update_hp();
    funcall(call,this_object(),"chk_all_shadows");

    if (peaced)
    {
        attacker_ob = 0;
        empty_hunted();
        vic = 0;
    }
    else if (attacker_ob)
    {
       vic = attacker_ob;
    }
    else if ( (tmp=present_hunted(my_env)) && !chk_invis(me,tmp) )
    {
       vic = tmp;
    }

    nhandle_spell();         // spell-timing; TAKE CARE: opponent may die or
                             // leave room in this function !!!!

    if ( !vic && aggressive )
        vic = looking_for_someone_to_attack(my_env);

    if ( spells || abilities )         // possibility to cast or spec. abili 
       handle_concentration( vic );

    achk = 0;
    if ( vic && environment(vic)==my_env )
    {
        attacker_ob = vic;

        // ----- multi-attacks
        if ( (achk = funcall(call,me,"attack",hands[0],0)) )
        {
/*
           sec_att = get_skill_value("second-attack");
           if ( sec_att && random(100) < sec_att )
              achk = me->attack(hands[0],0);
           i = 1;  
           mw = get_skill_value("multi-wield");
           achk = me->attack(hands[0],0);
 */
           i = 1;
           achk = 1;
           while ( i < number_of_arms && achk ) {
              if ( (hands[i] && random(100) < 40) ||
                   (!hands[i] && me->query_n_wc()) )
              {
                 achk = me->attack(hands[i],i);
/*
                 if ( achk && sec_att && random(100) < sec_att )
                    achk = me->attack(hands[i],0);
 */ 
              }
              i++;
           }
        }

        if ( achk ) {
           if (spell_chance && spell_chance > random(100))
           {
              say(spell_mess1 + "\n", attacker_ob);
              tell_object(attacker_ob, spell_mess2 + "\n");
              funcall(call,attacker_ob,"hit_player",random(max_spell_dam),5);
              if ( !(attacker_ob && living(attacker_ob)) ) achk = 0;
           }

           if(a_chat_chance && sizeof(a_chat_head)) 
           {
              c = random(100);
              if(c < a_chat_chance)
              {
                        c = random(sizeof(a_chat_head));
                        tell_room(environment(),process_string(a_chat_head[c]));
              }
           }
       }
    }

    if ( !achk ) {                            // victim fled or died
       if ( vic && !funcall(call,vic,"query_ghost") )
          add_hunted( vic );
       attacker_ob = 0;
    }

    if(!achk && !looking_for_someone_to_attack(my_env))
    {
       if(have_text && talk_ob) 
       {
           have_text = 0;
           test_match(the_text);
       } 
       attacker_ob = 0;
       my_env = me;                            // what the heck ????
       stop_heart_beat();
       abort_concentration();                  // abort spell if there is one
       return;
   }

   if(!achk && chat_chance)                    // talk, blah, blah, blah
   {
           c = random(100);
           if(c < chat_chance && sizeof(chat_head))
      {
                c = random(sizeof(chat_head));
                tell_room(environment(),process_string(chat_head[c]));
            }
    }

    if(!achk && random_pick)                   // pick something up
    {
            c = random(100);
            if (c < random_pick)
            pick_any_obj();
    }

    if(have_text && talk_ob)                   // blah, blah ?
    {
            have_text = 0;
            test_match(the_text);
    }
}

// ---------------------------------------------------------------------------
// handles the cast of spells and usage of abilities
// -> my current victim
// <- elimintated = 0; there is still a fight = 1;
// ---------------------------------------------------------------------------
private int handle_concentration( object victim )
{
   if ( funcall( call, this_object(), "concentrate", victim ) ) {
      if ( !victim || environment(victim) != environment(this_object()) )
         return( 0 );
   }
   return( 1 );
}

// ---------------------------------------------------------------------------
//   the function initializes spell casting. call it if you want a monster
//   to cast a certain spell
//   this function totally overrides the function of the living
//   -> name of the spell, string argument
//   <- successfully initiated = 1; otherwise 0
// ---------------------------------------------------------------------------
int nprocess_spell( string arg ) { return( 0 ); }

int npc_process_spell( string spn, string arg )
{
    int idx;
    string fn;          // the file with the spell_code

   if ( !spn ) return( 0 );                             // error on arguments
   if ( next_spell_time > -1 ) return( 0 );             // already casting
   if ( !spells ) return( 0 );                          // npcs has no spells
   if ( (idx = member_array( spn, spells[0] )) < 0 )    // no such spell known
       return( 0 ); 
   if ( !(fn=SPELL_MASTER->get_spell(spells[0][idx])) ) // no such spell in SM
      return( 0 );

   next_spell = fn;
   next_spell_arg = arg;
   next_spell_time = spells[3][idx];
   next_spell_data = ({spells[1][idx]}) + ({spells[2][idx]});

   funcall( call, next_spell, "display_utter", 2 );        // utter in magika

   if ( spells[3][idx] < 0 )                             // immediate
      nrelease_spell( ); 

   return( 1 );
}

// ---------------------------------------------------------------------------
//   the function initializes special abilities. call it if you want a monster
//   to use a certain special ability
//   this function totally overrides the function of the living
//   -> name of the ability, argument
//   <- successfully initiated = 1; otherwise 0
// ---------------------------------------------------------------------------
int process_ability( string arg ) { return( 0 ); }

int npc_process_ability( string abn, string arg )
{
    int idx;
    string fn;          // the file with the ability code

   if ( !abn ) return( 0 );                             // error on arguments
   if ( next_spell_time > -1 ) return( 0 );             // already concentr. 
   if ( !abilities ) return( 0 );                       // npcs has no abilit.
   if ( (idx = member_array( abn, abilities[0] )) < 0 ) // no such abil. known
       return( 0 ); 
   if ( !(fn=ABILITY_MASTER->get_ability(abilities[0][idx])) )  // no such abil 
      return( 0 );

   next_spell = fn;
   next_spell_arg = arg;
   next_spell_time = abilities[3][idx];
   next_spell_data = ({abilities[1][idx]}) + ({abilities[2][idx]});

   funcall( call, next_spell, "display_prepare" );

   if ( abilities[3][idx] < 0 )                             // immediate
      nrelease_spell( ); 

   return( 1 );
}


int check_wimpy( object attacker )   // 0=runaway, 1=still fighting
{
   object env;

   // monsters always succeed in running away at the moment

   if ( hit_point < max_hp*whimpy/100 ) {
      env = environment( this_object() );
      funcall( call,this_object(),"run_away" );
      if ( environment(this_object()) != env )     // succeeded to run away
         return( 0 );
   }

   return( 1 );
}

void add_hunted( object who )
{
   int size;

   if ( !who ) return;

   hunted -= ({ 0 });
   hunted -= ({who});
   size = sizeof( hunted );
   if ( size > MAX_HUNTED ) {
      if ( hunted[0]->query_hunter() == this_object() )
         hunted[0]->stop_hunter(1);
      hunted = del_array( hunted, 0 );
   }
   hunted += ({who});
}

void empty_hunted()
{
   hunted = ({});
}

object *get_hunted()
{
   hunted -= ({ 0 });
   return( hunted );
}

object present_hunted( object env )   // this is the fuck slow, needs recoding
{
   int    size;
   object who;

   if ( !env ) return( 0 );

   hunted -= ({ 0 });
   who = 0;
   size = sizeof( hunted ) - 1;
   while ( size >= 0 && !who ) {
      who = present( hunted[size], env );
      size--;
   }

   return( who );
}

int can_put_and_get(mixed str)
{
    if (!str)
             return 0;
    return 1;
}

int busy_catch_tell;

/* 
   Function: catch_tell
   The catch tell sends all strings of the environment and all tell
   messages, as all shouts to the monster. 
                                                                    */

void catch_tell(string str) 
{
    if (busy_catch_tell)
             return;
    busy_catch_tell = 1;

    if(talk_ob) 
    {
           if(have_text) 
      {
            test_match(the_text);
            the_text = str;
           } 
      else 
      {
             the_text = str;
             have_text = 1;
        }
    }
   busy_catch_tell = 0;
}

/*
   Function: set_name
   The set_name is very important it gives the monster an id. That means
   you can call the monster by the name. And it descripes the monster
   in the inventory of a player. When you like the short to do it just
   add a function in your file called:

                     int query_show_short()
                     { 
                         return 1;
                     }
                                                                  */
void set_name(string n) 
{
    name = n;
    real_race = n;              
    set_living_name(n);
    alignment = 0;              
    cap_name = capitalize( n );
    short_desc = cap_name;
    long_desc = "You see nothing special.\n";
}

/* USERDOC:
set_level
Format: set_level(i)
Example: set_level(10)
This function sets the level of the monster. This value may be anything between
1 and 100. The larger this value, the stronger the monster.
*/

void set_level(int l) 
{
    level = l;

    stats = ({ l, l, l, l, l, l });
    natural_ac = 2 + level/5;
    recalc_ac();
    hit_point = GM->query_maxhp(-1,l);
#if 0
    hit_point = 50 + (level - 1) * 8;   /* Same as a player */
#endif
    max_hp = hit_point;
    max_sp = spell_points = max_hp;

    experience = GM->query_exp(-1,l);

    if (experience == 0)
             experience = 100 + random(50);
    set_savings(level, 0);
}

/* 
   Function: set_alias
   This function adds a new id to the monster. For example when the name
   of the monster is wuki and the alias is monk wuki. You can call the 
   monster with wuki or monk wuki.
                                                                */
void set_alias(string a) 
{ 
     alias = a; 
}

/* 
   Function: set_alt_name
   This function adds a new id to the monster. For example when the name
   of the monster is wuki and the alt_name is monk wuki. You can call the 
   monster with wuki or monk wuki. All in all it does the same as upper
   function set_alias. Its just another possibility to give the monster
   an extra name.
                                                                */
void set_alt_name(string a) 
{ 
     alt_name = a; 
}

/* USERDOC:
set_race
Format: set_race(s)
Example: set_race("orc")
This function sets the race of the monster. This is also an alternative name,
but can be checked upon by weapons to see if they may kill it. Unfortunately
there is no convention on what races are allowed, though the player races (orc,
half-elf, elf, hobbit, human and troll) are certainly possible. This function
is optional, but it is strongly suggested that you use it.
*/

void set_race(string r) 
{ 
    real_race = r; 
}

/* USERDOC:
set_hp
Format: set_hp(i)
Example: set_hp(100)
This function sets the number of hitpoints of the monster, both the maximum and
the current hitpoints. You may put low values here, but it is strongly 
suggested that if the hp is lowered from the default value, another score is 
going up to make up for its level. This function is optional.
*/

void set_hp(int hp) 
{ 
    max_hp = hp; 
    hit_point = hp; 
}

/* USERDOC:
set_sp
Format: set_sp(i)
Example: set_sp(100)
This function changes the number of spellpoints of the monster, both the
maximum and the current value. The spellpoints of the monster are not used,
however. This function is optional.
*/

void set_sp(int sp) 
{ 
    max_sp = sp; 
    spell_points = sp; 
}

/* USERDOC:
set_ep
Format: set_ep(i)
Example: set_ep(1000)
This function changes the amount of experience one gets for the monster. This
amount can only be lowered. Note that the amount of experience set is not the
amount of experience a player gets for the monster: this amount is divided
before added to the player experience. This function is optional.
*/

void set_ep(int ep) 
{ 
    if (ep < experience) experience = ep; 
}

/* USERDOC:
set_al
Format: set_al(i)
Example: set_al(-500)
This function changes the alignment of the monster. A negative alignment means
an evil monster, and a positive alignment is a good monster. Neutral is the
default value. i may vary between -1000 and 1000, though exceptionally values
could be accepted if they are granted by Herp. This function is optional.
*/

void set_al(int al) 
{ 
    alignment = al; 
}

/*
  Function: set_short
  Descripes the name of a monster in your environment.
                                                            */
void set_short(string sh) 
{ 
     short_desc = sh; 
     long_desc = short_desc + ".\n";
}

/*
  Function: set_long
  Descripes a monster when you look at it.
                                                            */
void set_long(string lo) 
{ 
     long_desc = lo; 
}

/* USERDOC:
set_wc
Format: set_wc(i)
Example: set_wc(5)
This function sets the natural weapon class of the monster. This weapon class
is added to the weapon class the monster will get from any weapon it's
carrying. i may be any value between 0 and 20. This function is optional.
*/

void set_wc(int wc) 
{ 
    set_n_wc(wc); 
}

/* USERDOC:
set_ac
Format: set_ac(i)
Example: set_ac(2)
This function sets the natural armour class of the monster. this armour class
is added to any armour class the monster may be wearing. i has an undefined
range, but don't make it too high. This function is optional.
*/

void set_ac(int ac) 
{ 
    natural_ac = ac; 
    recalc_ac(); 
}

/* USERDOC:
set_move_at_reset
Format: set_move_at_reset()
This function makes the monster move every reset (approximately 45 minutes).
This is one of the least processor-consuming methods of moving the monster.
This function is optional.
*/

void set_move_at_reset() 
{ 
     move_at_reset = 1; 
}

/* USERDOC:
set_aggressive
Format: set_aggressive(i)
Example: set_aggressive(1)
This function lets the monster be peaceful or attack on sight. 0 (peaceful) is
the default value, 1 (attack on sight) can be entered. Once involved in a
fight, the monster will not stop fighting when 0 is entered into this function,
but the next person near the monster will not be attacked anymore, unless that
person was hunted by the monster or hunting the monster. This function is
optional.
*/

void set_aggressive(int a) 
{
    aggressive = a;
}

/* USERDOC:
set_no_steal
Format: set_no_steal()
This function makes it impossible for thieves to steal from the monster. This
function is optional.
*/

void set_no_steal() 
{ 
    no_steal=1; 
}

/* USERDOC:
set_no_ears
Format: set_no_ears()
See also: query_no_ears.
This function removes the ears from the monster, allowing it to safely interact
with bards... It has got no infuence on catch_tell. This function is optional.
*/

void set_no_ears() 
{ 
    no_ears=1; 
}

/* USERDOC:
set_has_gills
Format: set_has_gills()
See also: set_own_env, can_survive.
This function allows the monster to breathe underwater. This function is
outdated, please don't use it. If you want to do this, use the function
set_own_env("water").
*/

void set_has_gills() 
{ 
    ownenv="water"; 
}

/* USERDOC:
set_own_env
Format: set_own_env(s)
Example: set_own_env("water")
See also: set_has_gills, can_survive.
This function sets the environment the monster can move in. A possible
environment is 'water', allowing it to go under water without dying. This
function is optional.
*/

void set_own_env(mixed what) 
{ 
    ownenv=what; 
}

/* USERDOC:
set_trapped
Format: set_trapped(i)
Example: set_trapped(1)
See also: query_trapped.
This function sets if the monster is trapped or not. If a monster is trapped
its random_move function is disabled, which means it can't move (at least, if
this function is used to move the monster). The monster considers itself
trapped if i is unequal to zero, but it's better to use just the value 1. It
also prevents whimpying of the monster.
*/

int set_trapped(int d)   
{ 
    trapped = d; 
}

/* USERDOC:
query_trapped
Format: i=query_trapped()
See also: set_trapped.
This function returns the value set with set_trapped.
query_trapped() { 
  return trapped;
}

mixed run_away()
{
   if ( !trapped )
        ::run_away();
}

/* USERDOC:
can_survive
Format: s=can_survive()
See also: set_own_env, set_has_gills.
This function returns the value set by set_own_env, or "water" if set_has_gills
has been called. 
*/

mixed can_survive() 
{
    return ownenv;
}

/* USERDOC:
query_no_ears
Format: i=query_no_ears()
See also: set_no_ears.
This function tests if the monster has no ears. 0 is returned if it has ears.
*/

int query_no_ears() 
{
    return no_ears;
}

/* USERDOC:
set_prevent_poison
Format: set_prevent_poison(i)
Example: set_prevent_poison(1)
See also: query_prevent_poison,add_poison.
This function makes the monster immune to poisoning if i is unequal to zero.
*/

void set_prevent_poison(int i) 
{
    prevent_poison=i;
}

/* USERDOC:
query_prevent_poison
Format: i=query_prevent_poison()
See also: set_prevent_poison,add_poison, query_poisoned.
This returns if the monster is immune to poisoning. 1 is returned if it is.
*/

int query_prevent_poison() 
{
    return prevent_poison;
}

/* USERDOC:
add_poison
Format: add_poison(i)
Example: add_poison(1)
See also: set_prevent_poison,query_prevent_poison, query_poisoned.
This function poisons the monster. i is added to the amount of poison in the
bloodstream of the monster. Beware! Even low values of poison can be deadly for
monsters. A monster will not be poisoned if set_prevent_poison(1) is used.
*/

void add_poison(int amount) 
{
    if(prevent_poison) 
       return;
    if(!poisoner) 
    {
             poisoner=clone_object("players/cashimor/objects/poisoner");
             move_object(poisoner,this_object());
             funcall(call,poisoner,"set_owner");
    }
    funcall(call,poisoner,"add_poison",amount);
}

/* USERDOC:
query_poisoned
Format: i=query_poisoned()
See also: set_prevent_poison, query_prevent_poison, add_poison.
This function returns the amount of poison in the bloodstream of the monster.
*/

mixed query_poisoned() 
{
    if(!poisoner) 
        return 0;
    return funcall(call,poisoner,"query_poison_amount");
}

/* USERDOC:
set_chance
Format: set_chance(i)
Example: set_chance(20)
See also: set_spell_mess1, set_spell_mess2, set_spell_dam.
This function sets the chance a spell is cast. This can be a value between 1
and 100. Of course, 0 is default. When a chance other than 0 is set,
set_spell_mess1 and set_spell_mess2 should be called too.
*/

void set_chance(int c) 
{
    spell_chance = c;
}

/* USERDOC:
set_spell_mess1
Format: set_spell_mess1(s)
Example: set_spell_mess1("You are hit by a fireball!")
See also: set_chance, set_spell_mess2, set_spell_dam.
This function sets the message displayed on the screen of the player fighting
the monster when that player is hit by the spell. No \n is necessary.
*/

void set_spell_mess1(string m) 
{
    spell_mess1 = m;
}

/* USERDOC:
set_spell_mess2
Format: set_spell_mess2(s)
Example: set_spell_mess2("The Shaman casts a magic missile.")
See also: set_chance, set_spell_mess1, set_spell_dam.
This function sets the message displayed on everyone watching a player getting
hit by a spell. No \n is necessary.
*/

void set_spell_mess2(string m) 
{
    spell_mess2 = m;
}

/* USERDOC:
set_spell_dam
Format: set_spell_dam(i)
Example: set_spell_dam(5)
See also: set_chance, set_spell_mess1, set_spell_mess2.
This function sets the amount of damage the spell does. This is default 0.
Values higher than 20 make the monster rather dangerous.
*/

void set_spell_dam(int d) 
{
    max_spell_dam = d;
}

/* USERDOC:
set_frog
Format: set_frog()
This function makes the monster a frog, which means that everyone kissing it
will turn into a frog if it isn't already one. This function is optional.
*/

void set_frog() 
{
    frog = 1;
}

/* USERDOC:
set_whimpy
Format: set_whimpy([i])
Example: set_whimpy(10)
This function sets the percentage of hitpoints on which the monster will
attempt to run away. If no argument is supplied, 20 is assumed. i may be
between 0 (brave) and 100. If the monster is trapped, then it can't run away
even though whimpy is set. Default value is 0. This function is optional.
*/

void set_whimpy(int arg) 
{
    if(!arg) 
       whimpy=20;
    else 
       whimpy = arg;
}

/*
   Function: Tame
   Its for the Mages purpose to make an aggressive monster none
   aggressive. The tames is asked in the init of the monster.
                                                                    */
void set_tame(object ob) 
{
    tamer=ob;
}

object tamer() 
{ 
   return tamer; 
}

/* USERDOC:
init_command
Format: init_command(s)
Example: init_command("wear armour")
This function executes s as a command for the monster. However, it's possible
to use the EFUN command now for this purpose, so this function is obsolete.
*/

void init_command(string cmd) 
{
    command(cmd);
}

/* USERDOC:
load_chat
Format: load_chat(i,s)
Example: load_chat(10,({"The orc spits on the floor.","The orc giggles."}))
See also: load_a_chat.
This function lets the monster make noises once in a while. The noises are
noted in an array s, and the chance each round that a noise may be heard is i.
Don't make i too high or one will get crazy with all the message (not to speak
of the lag it causes).
*/

void load_chat(int chance,mixed strs) 
{
    if (!sizeof(strs))
        chat_head = ({ strs });
    else 
        chat_head = strs;
    chat_chance = chance;
}

/* USERDOC:
load_a_chat
Format: load_a_chat(i,s)
Example: load_a_chat(20,({"The orc screams.","The orc looks angry."}))
See also: load_chat
Well, the chats loaded with load_chat() are interesting, but not applicable in
fight, so with this function you can set the chats that are displayed when the
monster is in a fight. The chance may be higher here, because there are already
a lot of messages in a fight.
*/

void load_a_chat(int chance,mixed strs) 
{
    if (!sizeof(strs))
        a_chat_head = ({ strs });
    else
        a_chat_head = strs;
    a_chat_chance = chance;
}

/* USERDOC:
set_match
Format: set_match(o,s1,s2,s3)
Example: set_match(this_object(),({"giggle_it"}),({"giggles"}),({""}))
o is the object where the functions from array s1 are stored, s2 is the word
on which the match is made and I haven't figured out s3 yet. This function will
call the function in s1 if the monster catches a sentence in which the piece
mentioned in s2 appears. This may sound difficult, but it can be used to make
the monster react to things said or done in its environment.
*/

varargs void set_match(object ob,mixed func,mixed type,mixed match) 
{
    object old;

    if (sizeof(func) != sizeof(type) || sizeof(match) != sizeof(type))
        return;
    talk_ob = ob;
    talk_func = func;
    talk_type = type;
    talk_match = match;
#if 0
    say("talk match length " + sizeof(func) + "\n");
#endif
}

/* USERDOC:
set_dead_ob
Format: set_dead_ob(o)
Example: monster->set_dead_ob(this_object())
This function defines a certain object as the object where monster_died()
should be called if the monster dies. If monster_died returns a value other
than 0 the monster will remain alive even though it was killed. o is usually
set to the room the monster is in.
*/

void set_dead_ob(object ob)
{
    dead_ob = ob;
}

/* 
   Function: second_life
   Normally it returns 0 what means the monster will die when its hitpoints
   are below 0. But when you set the function set_dead_ob(this_object())
   into your monsterfile, you can overwrite this function. Any other return
   than 0 means the monster wont die. 
                                                                       */
   
mixed second_life()
{
   if(dead_ob)
            return funcall(call,dead_ob,"monster_died",this_object());
   return 0;
}

/* USERDOC:
set_random_pick
Format: set_random_pick(i)
Example: set_random_pick(1)
This function makes the monster pick up any object it encounters on its
travels. Interesting in combination with set_move_at_reset(). i is the chance
that the monster picks up something (0-100).
*/
void set_random_pick(int r)
{
    random_pick = r;
}

/* USERDOC:
pick_any_obj
Format: pick_any_obj()
See also: set_random_pick.
This function makes the monster pick up any object that might be lying near it.
*/

void pick_any_obj() 
{
   object env, *inv, *gotten, best_weapon, old_weapon;
   int i, sz, old_class, new_class;
   string oname, bname;

   env = environment();

   if (my_env == env)
       return;
   
   if (stringp(funcall(call,env,"query_type")))
   {
       if (objectp(has_bag) && environment(has_bag)==me)
       {
           bname = funcall(call,has_bag,"query_name");
           init_command("drop "+bname);
           call_out("sell_all_bag",1,bname);
       }
       init_command("sell all");
       return;
   }

   inv = all_inventory(env) - ({me});
   gotten = inv;

   if ( (old_weapon = funcall(call,me,"query_wielded")) )
         old_class = funcall(call,old_weapon,"weapon_class");
   else
         old_class = 1;

   for(sz=sizeof(inv),i=0;i<sz;i++)
   {
     if ( !living(inv[i]) && (oname=funcall(call,inv[i],"query_name")) )
     {
       if ( !funcall(call,inv[i],"get") || transfer(inv[i],this_object()) ) 
       {
                      say(cap_name + " tries to take " + oname + " but fails.\n");
            gotten = gotten - ({ inv[i] });
       }
       else 
       {
                say(cap_name + " takes " + oname + ".\n");
           if ( (!objectp(has_bag) || environment(has_bag)!=me)
                 && funcall(call,inv[i],"query_container"))
           {
                has_bag = inv[i];
           }
                if ( (new_class=funcall(call,inv[i],"weapon_class")) )
           {
                if (old_class < new_class)
                {
                    old_class = new_class;
                    best_weapon = inv[i];
                }
           }
                else if ( funcall(call,inv[i], "armour_class") ) 
                          init_command("wear "+oname);
        }
     }
     else
       gotten = gotten - ({ inv[i] });
  }
  if (objectp(best_weapon))
      call_out("wield_the_best",2,({old_weapon,best_weapon}));
  if (objectp(has_bag) && sizeof(gotten))
      call_out("put_in_bag",4,gotten);
}

/* 
   Function: sell all bag 
   The monster tries to see all she has in her bag.
                                                                  */
void sell_all_bag(string bname)
{
     if (has_bag && command("get "+bname))
     {
         init_command("get all from "+bname);
         init_command("sell all");
// sells the bag too
         has_bag = 0;
     }
}

/* 
   Function: Put in bag
   To save weight the monster puts something in a bag.
                                                                  */

void put_in_bag(object *inv)
{
   int i,sz, max_weight, weight;
   object weapon;
 
   if (!objectp(has_bag) || environment(has_bag)!=me) 
   {
         has_bag = 0;
         return;
   }

   weapon = funcall(call,me,"query_wielded");
   max_weight = funcall(call,has_bag,"query_max_weight");
   weight = funcall(call,has_bag,"query_weight");
 
   for (sz = sizeof(inv),i=0; i < sz; i++)
   {
       if (inv[i] && inv[i]!=weapon && !funcall(call,inv[i],"query_worn"))
       {
           weight = weight + funcall(call,inv[i],"query_weight");
           if (weight >= max_weight)
               return;
           init_command("put "+funcall(call,inv[i],"query_name")+" in "+
                        funcall(call,has_bag,"query_name"));
       }
   }
   return;
}
             
/*
   Function: wield the best
   After the random pick the monster tries to wield the best weapon.
                                                                      */

void wield_the_best(mixed *ob)
{
    string oname;
    mixed obarr;
    
    if (!ob) 
         return;

    obarr = ob;
    if (obarr[0])
    {
       oname = funcall(call,obarr[0],"query_name");
       init_command("unwield "+oname);
       say(query_name()+" unwields the "+oname+".\n",me);
    }
    init_command("wield "+funcall(call,obarr[1],"query_name"));
    return;
}


/* USERDOC:
set_init_ob
Format: set_init_ob(o)
Example: monster->set_init_ob(this_object())
This function sets the object in which monster_init() is called each time
something enters near the monster. If monster_init() returns something unequal
to zero the init in the monster is stopped and the monster will not attack, 
even if it's aggressive.
*/

set_init_ob(ob)
{
    init_ob = ob;
}

/*
   Function: update_hp
   This function is used instead of heal slowly, it raises the hit,
   btw spellpoints of the monster, after a passes time in the init.
   The returned value is the time which passed during the last init
   divided by the intervall of healing, which is defined in the
   header.
                                                                   */

int update_hp(){
  int time_passed;
  int temp;
  
  if (!hit_point) 
    return 0;
  
  time_passed = time()-healing_time;
  
  if (time_passed > (HEAL_INTERVAL-1)) { 
    temp = time_passed/HEAL_INTERVAL;
    healing_time += (temp*HEAL_INTERVAL);

  //Next line add by blade to allow poison to work on mobs 4-21-96
 //Installed by Haplo
    if(!poisoner)
      hit_point += (temp* funcall(call,this_object(),"query_con")*HEAL_FACTOR);
    spell_points +=(temp* funcall(call,this_object(),"query_int")*HEAL_FACTOR);
    
    if (hit_point > max_hp) 
      hit_point = max_hp;
    if (spell_points > max_hp) 
      spell_points = max_sp;
  }
  return temp;
}

int chk_attack(object food)
{
    if ( !food ) return( 0 );
    return( interactive(food) ? 1 : 0 );
}


void init() 
{
    int    temp;
    object vic;

    ::init();

    peaced = 0;

    if (!heart_beat_stat) 
    { 
        update_hp(); 

        if (this_player()==me) return;

        if ( !attacker_ob && !chk_invis(this_object(),this_player()) &&
             tamer != this_player() && !(this_player()->query_sneaking()) )
        {
           if ( (aggressive && chk_attack(this_player())) 
                || (this_player()->query_hunter() == this_object()) )
           {
              attacker_ob = this_player();
           }
       }
       start_heart_beat();
    }

    if (!create_room) create_room = environment(me); /*HERP*/

    if ( init_ob ) {
       log_file( "MONSTER_INIT", file_name(this_object())+" " );
       if ( create_room ) log_file("MONSTER_INIT",file_name(create_room)+"\n");
       else               log_file("MONSTER_INIT","NO ENVIRONMENT !!!\n" );
       funcall(call,init_ob,"monster_init",this_object());
    }
}

#if 1
int xx() 
{
    command(funcall(call,master_object(),"modify_command_global",query_verb()));
    write(funcall(call,environment(),"short")+".\n");
    return 1;
}
#endif

object query_create_room() 
{ 
      return create_room; 
}

/* USERDOC:
query_no_steal
Format: i=query_no_steal()
See also: set_no_steal.
This function returns if the monster can be stolen from. 0 means it's possible.
*/

int query_no_steal() 
{ 
    return no_steal; 
}

/* USERDOC:
query_aggressive
Format: i=query_aggressive()
See also: set_aggressive.
This function returns if the monster will attack on sight. 0 means it won't,
1 means it will.
*/

int query_aggressive() 
{ 
    return aggressive; 
}

mixed test_match(string str) 
{
    string who, str1;
    mixed type, match, func;
    int i;

    while(i < sizeof(talk_match)) 
    {
            if (talk_type[i])
                type = talk_type[i];
            match = talk_match[i];
            if (match == 0)
                match = "";
            if (talk_func[i])
                func = talk_func[i];
            if (sscanf(str,"%s " + type + match + " %s\n",who,str1) == 2 ||
                sscanf(str,"%s " + type + match + "\n",who) == 1 ||
                sscanf(str,"%s " + type + match + "%s\n",who,str1) == 2 ||
                sscanf(str,"%s " + type + " " + match + "\n",who) == 1 ||
                sscanf(str,"%s " + type + " " + match + " %s\n",who,str1) == 2)
            {
                return funcall(call,talk_ob, func, str);
            }
            i += 1;
    }
}

/*
 * The monster will heal itself slowly.
 */
void heal_slowly() 
{
    if (hit_point > max_hp/4)
             hit_point += 120 / (INTERVAL_BETWEEN_HEALING * 2);
    if (hit_point > max_hp)
             hit_point = max_hp;

    spell_points += 120 / (INTERVAL_BETWEEN_HEALING * 2);

    if (spell_points > max_hp)
        spell_points = max_hp;
    healing = 1;

    if (hit_point < max_hp || spell_points < max_hp)
        call_out("heal_slowly", 120);
    else
           healing = 0;
}

mixed add_history(mixed a) 
{ 
    return a; 
}

#ifdef CLEANUP
// docu is wrong: arg >= 2 == inheritance
int clean_up(int arg) 
{
    object *inv;
    int i, sz;

//  log_file("CLEAN_UP","MONSTER: "+file_name(this_object())+", arg="+arg+" ");
    if ( environment() )  {              // wait until the env cleans me
//     log_file("CLEAN_UP", "EXIT: env\n" );
       return( 1 );
    }

    inv = deep_inventory();
    for ( sz=sizeof(inv),i=0;i<sz;i++ )
       destruct(inv[i]);

//  destruct them anyway, there are too many of them in the obj-dump 
//    if ( arg > 1 ) return( 0 );      // used for inheritance, do not clean it

//  log_file("CLEAN_UP", "CLEARED !\n" );
    destruct(this_object());
    return 0;
}
#endif

int query_ghost()
{
    return 0;
}

int stop_fight ()
{
     return( peaced = ::stop_fight() );
}

varargs mixed hit_player(int dam,int kind,mixed elem)
{
   peaced = 0;
   dam = ::hit_player(dam,kind,elem);

   if (!heart_beat_stat)
   {
         start_heart_beat();
         heart_beat();
   }
   return( dam );
}

private void start_heart_beat()
{
   heart_beat_stat = 1;
   set_heart_beat( 1 );
}

private void stop_heart_beat()
{
   heart_beat_stat = 0;
   set_heart_beat( 0 );
}

int attack_object( object ob )
{
   int ret;

   ret = ::attack_object( ob );
   if ( ret )
      start_heart_beat();
   return( ret );
}

int attacked_by( object ob )
{
   int ret;

   ret = ::attacked_by( ob );
   if ( ret )
      start_heart_beat();
   return( ret );
}
