/* USERDOC:
general
Include this file in objects that "lives". Genderhandling, Stathanding and
wizardqueries are mentioned in /obj/livingadd.c, which is documented too. 
Generally defined functions:
query_name, query_value, query_weight, set_weight.
*/

#include "/sys/living_defs.h"   // the general defines
#include "/sys/levels.h"

// static - PROTOTYPING
static void release_spell(mixed fn,mixed sd,int flag );
static void nrelease_spell( );
static mixed _query_hit_msg(int tmp,string name,object att,object def); 
static void rep_follow_obj();
static mixed chk_follow(object fol,object whom);
static string encrypt_msg( string msg, int lvl );

// private - PROTOTYPING

private void stat_changed( int stat );
private int  do_die( object killer );

// global VARIABLES (this will be saved!)
// scores
string name;                     /* Name of object. */
string race;                     /* Race of a living, default is human */
int    level;                    /* Level of monster. */
int    size;                     /* Size of a monster 1-6 */
int    weight;                         /* our weight, dependig on size */
int    money;                    /* Amount of money on player. */
int    hit_point;                 /* current hit points. */
int    spell_points;             /* Current spell points. */
int    max_hp, max_sp;           /* Max hit and spell points */
int    experience;               /* Experience points of monster. */
int    age;                      /* Number of heart beats of this character. */
int    alignment;                /* the alignment of the char */
int    gender;                         /* 0=other 1=male 2=female */
int    guild;                         /* which guild do we belong to */
int    *stats;                   /* the stats in an array */
mixed  *skills;                  /* the skills of the living */
mixed  *spells;                  /* the spells of the living */
int    *languages;               // languages
mapping nskills;                 // skill-values (the new skill-system)

int    time_to_heal;             /* Count down variable. */

string msgin, msgout;            /* Messages when entering or leaving a room. */
string mmsgout;                  /* Message when leaving magically. */
string mmsgin;                         /* Message when arriving magically. */
string my_smell;                 /* smell of living */
string real_race;                /* needed when frog-cursed */
int    real_size;                 /* the real size before cursed */
int    whimpy;                   /* Automatically run when low on HP */

int    is_npc, brief;            /* Flags. */
int    is_wizard;                /* are we a wizard ? */
int    ghost;                    /* Used for monsters that can leave a ghost */
int    is_invis;                 /* True when player is invisible */
int    frog;                     /* If the player is a frog */ 
int    no_fight;                       
int    dead;                     /* Are we alive or dead? */

int    spend_points;             /* points from advancing ...  */
string auto_load;                /* Special automatically loaded objects. */
string flags;                    /* Bit field of flags */

static status backstab_check;   /* for thief guild */
static closure call;             /* direct addressator */
static string *sizes = SIZES;    /* strings for sizes */
static object last_attacker;     /* The one who attacked last. */
static object attacker_ob;         /* Name of player attacking us. */
static int    weapon_class;      /* the class of the weapon */
static object *hands;            /* an array of what the hand is holding */
static int    number_of_arms;    /* How many arms do we have */
static object head_armour;         /* What armour we have. */
static int    armour_class;      /* What armour class of monster. */
static int    natural_ac;        /* natural armour class of living */
static int    natural_wc;        /* natural weapon class of living */
static int    local_weight;         /* weight of items */
static object hunter;            /* used in the hunt mode */
static string cap_name;          // capitaized name 
static object *armour;           /* Array of armours */
static string *arm_types;        /* Array of armourtypes */
static object *rings;            /* Array of worn rings */
static int    ring_cnt;                 /* Counter of worn rings */
static object *others;           /* Array of worn others */
static int    other_cnt;         /* Counter of worn others */
static int    hold_flag;         /* holding us ? */
static object *follow_obj;         /* who follows me? */
static object follow_whom;       /* whom do i follow? */
static object rid_whom;          /* whom do you want to get rid of ? */
static string last_cmd;          /* used for follow */
static string prep_spell;        /* which spell next, -1 is none  */
static string spell_arg;         /* arg given for the spell       */
static int    spell_time;        /* when to release the spell     */
static int    *spell_data;       /* [0]: skill, [1]: max_skill    */
static int    _speaks_in;        // which lang do i speak now
static string next_spell;        // which spell next
static string next_spell_arg;    // argument for the next spell to cast
static int    next_spell_time;   // when to release the spell
static int    *next_spell_data;  // [0]: actSkill, [1]: max_skill
static int    is_hidden;         // flag if the player is hidden
static int    is_sneaking;       // sneaking-counter for the player
static int    infravis;          // do not save it, bugs could arise

static private int *stat_modifiers;   // modifiers for stats

#include "log.h"
#include "properties.h"
#include "descs.h"
#include "/obj/lw.h"
#include "/obj/fit.c"
#include "/spells/spell.h"
#include "/sys/savings.c"
#include "/sys/abilities.c"


/* just a test*/
string modify_command(string str) { 
    return str; 
}

set_command_modifier() { 
    set_modify_command(TO); 
}

int query_exp_next_level() {  // no shadow of level in THIS function !!! (pat)
    return( funcall(call,GM,"query_exp",-1,level+1) );
}

int abort_concentration() {
    if ( next_spell_time >= 0 ) {
       next_spell_time = -1;
       next_spell = 0;
       next_spell_arg = 0;
       next_spell_data = 0;
    }
    return 1;
}

// the reset to inizialize variables

void reset(string arg) {

    object infra;
    int    i;

    if (arg!=0) return;

    call = #'call_other;   /* inizializing the closure */
    cap_name = "";
    stats=allocate(NUM_STATS);
    sizes=funcall(call,SHARE,"share_armour_sizes"); /* shared array */
    set_size(3);
    hold_flag=0;
    arm_types=funcall(call,SHARE,"share_armour_types"); /* shared array */
    armour=allocate(sizeof(arm_types));
    rings=allocate(RING_NUM);
    others=allocate(10);
    ring_cnt=other_cnt=0;
    hands = ({0});                        /* init the array            */
    number_of_arms = 1;                   /* default for our arms (pat) */
    spell_time = -1;                      /* no spell to be released (pat) */

    _speaks_in = 0;                       // default = common
    init_savings(MAX_NO_OF_SAVE+1);          // initialize the saving throws
    next_spell_time = -1;                 // time to release next spell =NONE

    stat_modifiers = ({0,0,0,0,0,0});     // stat-modifiers
}

void init() {
}


// the groupfollow 
static void rep_follow_obj() {

    int i;

    if(!follow_obj) return;

    while((i=member_array(0,follow_obj))!=-1) 
        follow_obj=del_array(follow_obj,i);
}

static mixed chk_follow(object fol,object whom) {
    int i, sz;
    object *list;

    list = funcall(call,whom,"query_followers");

    // she follows herself or she has no followers else she has followers
    if(whom==TO || !list)  
        return 0;
    else if(member_array(fol,list)!=-1)  
        return 1; 
    return 0;
}

void de_hold(object obj) {
    if(interactive(this_object())) enable_interactive(this_object());
    hold_flag=0;
    if(obj) funcall(call,obj,"hold_end",TO);
}

string query_name_true() {
    if (ghost)
        return NAME_OF_GHOST;
    return cap_name;
}

string query_name_info() {

    string name;
    if(!name) name = "";

    if (ghost)
        return NAME_OF_GHOST;
    if ( previous_object() ) {
       if ( this_object()->is_invis_for(previous_object()) )
          return( INVNAME );
       if ( this_object()->query_invis() )
          return( cap_name+name+" (invis)" );
       if ( this_object()->query_hidden() )
          return( cap_name+name+" (hidden)" );
       return( cap_name+name );
    }
    return( INVNAME );
}

string query_name_rdr() {
    string name;
    if (ghost)
        return NAME_OF_GHOST;
    if(!previous_object() || 
      funcall(call,this_object(),"is_invis_for",previous_object()) )
        return INVNAME;
    return cap_name;
}

/* pat: this function needs the name of the weapon, which should be   *
        stopped wielded. returns 0 or -1 if not wielded by us         */ 

int stop_wielding(object weapon) {

  int i, res;

  if ( !weapon ) weapon = hands[0];           // to ensure compatibility
  if ( !weapon ) return(0);                   // none wielding

  res = 0;
  for ( i = 0; i < number_of_arms; i++ ) {
    if ( hands[i] == weapon ) {
      hands[i]->un_wield();
      hands[i] = 0;
      res = 1;
    }
  }
  return( res );
}

void stop_wearing(object a, int silent) {

  int typ,i,k,l,fl,sz;

// ---- only armour my call this !!! (pat)
  if ( !previous_object() || !(previous_object()->query_armour()) )
    return;

  if(arm_types) {
    for(sz = sizeof(funcall(call,a,"get_type")),k=0; k < sz;k++) {
      typ=query_arm_types((funcall(call,a,"get_type"))[k]);
      if (typ!=-1) {
        switch(arm_types[typ]) {
          case "ring":
            for(i=0;i<ring_cnt;i++) if(rings[i]==a) rings[i]=0;
            break;
          case "other":
            for(i=0;i<other_cnt;i++) if(others[i]==a) others[i]=0;
            break;
          default:
            if(armour[typ]=a) 
              armour[typ]=0;
        }
      }
    }
    recalc_ac();

    if(!is_npc && !dead && funcall(call,a,"short")) {
      say(TName + " removes " + funcall(call,a,"query_name") + ".\n",0,TO,"");
      if(!silent) 
        write("Ok.\n");
    }
  }
}

/* proto */
int recalc_ac() {

  int i,j,l,fl;

  if(!arm_types) {
    armour_class=natural_ac;
    return 1;
  }
  fl=0;
  for(i=l=0;i<ring_cnt;i++) {
    if(!rings[i]) 
      fl=1;
    else {
      rings[l]=rings[i];
      l++;
    }
  }
  if(fl) {
    ring_cnt=l;
    if(l) {
      armour[1]=rings[0];
      for(i=0;i<ring_cnt;i++)
        if(armour[1]->armour_class()< funcall(call,rings[i],"armour_class"))
          armour[1]=rings[i];
    } 
    else armour[1]=0;
  }  
  fl=0;
  for(i=l=0;i<other_cnt;i++) {
    if(!others[i]) 
      fl=1;
    else {
      others[l]=others[i];
      l++;
    }
  }
  if(fl) {
    other_cnt=l;
    if(l) {
      armour[0]=others[0];
      for(i=0;i<other_cnt;i++)
        if(funcall(call,armour[0],"armour_class") <
          funcall(call,others[i],"armour_class"))
          armour[0]=others[i];
    } 
    else 
      armour[0]=0;
  }  
  armour_class=natural_ac;
  for(i=0;i<sizeof(armour);i++)
    if(armour[i]) {
      for(j=0,fl=1;j<i;j++) 
        if(armour[i]==armour[j]) 
          fl=0;
        if(fl) 
          armour_class+=funcall(call,armour[i],"armour_class");
    }
  return 1;
}

/*
 * Return true if there still is a fight.
 * theWeapon: weapon to use in the function
 * nrOfHand: the index of the hand (0 .. <number of hands - 1>)
 */

varargs int attack( object theWeapon, int nrOfHand ) {

  int tmp, sz;
  int whit,hit_count, weap_class, edam;
  string name_of_attacker;
  object room,tp,ob, weap, hit_weaps;

  is_hidden = 0;

  if (no_fight) {
    if(attacker_ob) {
      funcall(call,attacker_ob,"stop_fight");
      funcall(call,attacker_ob,"stop_hunter",1);
    }
    stop_fight();
    stop_hunter(1);
    return 0;
  }
  if (!attacker_ob) {
    return 0;
  }
  if (attacker_ob==this_object()) {
    stop_fight();
    return 0;
  }

  if (!is_npc && environment()
          && funcall(call,environment(),"query_property","no_fight")
          && attacker_ob
          && environment(this_object()) == environment(attacker_ob) ) {
    write("You are not allowed to fight here.\n");
    tell_object(attacker_ob,funcall(call,this_object(),"query_name")+
                            " tried"+" to attack you.\n");
    funcall(call,attacker_ob,"stop_fight");
    funcall(call,attacker_ob,"stop_hunter",1);
    stop_fight();
    stop_hunter(1);
    room = environment();
    funcall(call,room,"try_attack",this_object());
    return 0;
  }

  name_of_attacker = funcall(call,attacker_ob,"query_name");
  if (funcall(call,attacker_ob,"query_linkdeath")) {
    write("You cannot kill "+name_of_attacker+
          ". "+name_of_attacker+" is linkdead.\n");
    stop_fight();
    return 0;
  }
  if (!name_of_attacker
                || name_of_attacker == NAME_OF_GHOST
                || environment(attacker_ob) != environment(this_object())) {
    return( 0 );
  }

  if (theWeapon && funcall(call,theWeapon,"query_weapon") )
    weap = theWeapon;
  else if(sizeof(hands)>0) 
    weap=hands[0];
  else 
    weap=0;

  if(weap) {
    weap_class = weap->weapon_class() + this_object()->stat_dam(weap)/2;
    whit = weap->hit(attacker_ob);

    if (!attacker_ob) {
      tell_object(this_object(), "CRACK!\nYour weapon broke!\n");
      log_file("BAD_SWORD", weap->short()+", "+creator(weap)+" XX !\n");
      destruct(weap);
      return( 0 );
    }
  }
  else if ( !is_npc ) {
    if ( this_object()->query_n_wc() )
      weap_class = this_object()->query_n_wc();
    else
      weap_class = this_object()->query_str()/4 + 1;
  }
  else {
    weap_class = this_object()->query_n_wc() + edam +
            (this_object()->query_str()*3/2+this_object()->query_dex()/2)/2;
  }

  tmp = weap_class + this_object()->enhanced_dam();

  if (tmp < 1) tmp = 1;

  if (whit) tmp = random(tmp + whit);
  else      tmp = random(tmp);

  if(weap) tmp+=weap->_voiinskreiz();

  if ( attacker_ob->parry(tmp) )
    tmp = -1;
  else
    tmp = funcall(call,attacker_ob,"hit_player",tmp,0);

  if (tmp == 0) {                              
    if(attacker_ob) {
      tell_object(this_object(), "You missed.\n");
      say(TName+" missed "+name_of_attacker+".\n",attacker_ob,TO,
                TName+" missed "+name_of_attacker+".\n");
      tell_object(attacker_ob,query_name() + " missed you.\n");
    }
  }
  else if ( tmp == -1 ) {
    tell_object(this_object(), name_of_attacker+" parried your hit.\n");
    say(TName+" parried "+name_of_attacker+"'s hit.\n",attacker_ob,TO,
    TName+" parried "+name_of_attacker+"'s hit.\n");
    tell_object(attacker_ob,"You parried "+query_name() + "'s hit.\n");
  }
  else {
    experience += tmp;

    if(attacker_ob
               && funcall(call,attacker_ob,"query_name",0) != NAME_OF_GHOST) {
      string *msg;
      if ( environment(attacker_ob) != environment(this_object()) )
        return( 0 );

      if( weap ) 
        msg=funcall(call,weap,"query_hit_msg",tmp, name_of_attacker,
                      TP,attacker_ob);
      else 
        msg=funcall(call,TO,"query_hit_msg",tmp, name_of_attacker,
                      TP,attacker_ob);

      if(!msg || sizeof(msg)!=3)
        msg=_query_hit_msg(tmp,name_of_attacker,TP,attacker_ob);

      tell_object(this_object(), "You " + msg[0] + "\n");
      tell_object(attacker_ob, query_name() + " " + msg[1] + "\n");

      say(TName + " "+msg[2]+"\n",attacker_ob,TO, IName+" "+msg[2]+"\n");
    }
    else {
      tell_object(TO, "You killed "+name_of_attacker+".\n");
      say(TName+" killed "+ name_of_attacker +".\n",0,TO,
                 IName+" killed "+ name_of_attacker +".\n");
      return( 0 );
    }
  }

  if(attacker_ob)
    return(funcall(call,attacker_ob,"check_wimpy",this_object()) );

  return( 0 ); 
}

int parry( int dam ) {                         // 1: parried, 0: not parried

  int i, h;

  if ( dam > 50 ) return( 0 );                // cannot parry hits > 50
  h = sizeof( hands );
  i = 0;
  while ( i < h && !hands[i] ) i++;
  if ( i < h && nskills && nskills["parry"] ) {
    if ( nskills["parry"][0] > random(500) )
      return( 1 );
  }
  return( 0 );
}

int get() { 
  return 0; 
}


mixed query_hit_msg(int tmp,string name,object att,object def) {
  return _query_hit_msg(tmp,name,att,def);
}

static mixed _query_hit_msg(int tmp,string name,object att,object def) {
  string what,how;

  switch (tmp) {
    case 1:     
      how = " in the stomach";
      what= "tickled";
      break;
    case 2:        
      how = "";
      what= "grazed";
      break;
    case 3..4:   
      how = "";
      what= "hit";
      break;
    case 5..9:        
      how = " hard";
      what= "hit";
      break;
    case 10..14: 
      how = " pretty hard";
      what = "hit";
      break;
    case 15..19: 
      how = " very hard";
      what= "hit";
      break;
    case 20..29: 
      how = " extremely hard";
      what = "hit";
      break;
    case 30..39: 
      how = " with a bone crushing sound";
      what = "smashed";
      break;
    case 40..49: 
      how = " to small fragments";
      what = "massacred";
      break;
    case 50..59: 
      how = " into a puddle of blood and body parts";
      what = "pounded";
      break;
    case 60..69:
      how = " with a hit";
      what = "obliterated";
      break;
    case 70..79:
      how = " with a ferocious hit";
      what = "annihilated";
      break;
    case 80..89:
      how = "";
      what = "did an insane amount of damage to";
      break;
    default: 
      how = " with a devastating blow";
      what = "massacred";
      break;
  }
  return ({ what + " " + name + how + ".",
            what + " you" + how + ".",
            what + " " + name + how + "." });
}

/* proto */
int dodge_bon(object vic) {

  int bon;
  int vic_dex;  /* dex of the victim */

  if ( hold_flag == 1)              // PAT: roland, bitte recode das *smile*
    return 0; 

/* a monster dont carry weight mostly */
  if (!interactive(this_object()))
    bon =  query_dex() / 5; /* maximal 20 */
  else 
    bon =  (query_dex() * 3 / 2) - query_weight(); /* maximal 30 */

  if (objectp(vic) && living(vic) &&  bon > 0 ) {
    vic_dex = 2 * funcall(call,vic,"query_dex");  /* maximal 200 */

    if (bon > (vic_dex/2))
      bon = vic_dex /2;

    if ( random(vic_dex) < bon) /* dodged */
      return 1;
  }
  return 0;
}

/* the damage bonus for the weapon */
int stat_dam(object weap) {

  int type;

  if(!weap) 
    type = 0;
  else 
    type = funcall(call,weap,"query_weapon_type");

  if(!intp(type)) 
    type = 0;

  switch(type) {
    case 1: 
      return  (3 * funcall(call,TO,"query_str"));
    case 2: 
      return  (2 * funcall(call,TO,"query_dex"));
    default: 
      return (funcall(call,TO,"query_dex") + funcall(call,TO,"query_str")*3/2);
  }
  return 0;
}

/* Wield a weapon. */
// returns an array with the hands i am wielding this weapon with
// or 0 on failure
mixed wield(object w, int hands_needed ) {

  int free_hands, i;

  if ( hands_needed < 1 )                             // would be rediculous
    hands_needed = 1;
  if (query_hands_free() < hands_needed)              // enough hands free ?
    return 0;

  if ( member_array( w, hands ) > -1 ) {              // already wielded ?
    write( "You already wield this weapon.\n" );
    return( 0 ); 
  } 

  i = 0;
  while ( i < number_of_arms && hands_needed > 0 ) {
    if ( !(hands[i]) ) {
      hands[i] = w;
      hands_needed--;
    }
    i++;
  }

  say(TName +" wields "+funcall(call,w,"query_name")+".\n",0,TO,"");
  return( where_holding(w) );
}

void re_wear() {
  recalc_ac();
}

/* Wear some armour. */
mixed wear(object a) {

  mixed *t;
  object old;
  int typ;
  int i,j,sz;

  t=funcall(call,a,"get_type");

  for(sz = sizeof(t),i=0;i<sz;i++) {
    typ=query_arm_types((t)[i]);

    if(typ>1 && armour[typ]) 
      return armour[typ];
    else if(typ==1 && ring_cnt==RING_NUM) 
      return armour[typ];
    else if(typ==0 && other_cnt==100) 
      return;
  }

  for(sz=sizeof(t),j=0;j<sz;j++) {
    typ=query_arm_types(t[j]);

    switch(arm_types[typ]) {
      case "ring":
        rings[ring_cnt]=a; 
        ring_cnt++;
        if(!armour[typ]
              || (funcall(call,armour[typ],"armour_class") <
                                  funcall(call,a,"armour_class")))
          armour[typ]=a;
        break;
      case "other":
        others[other_cnt]=a; other_cnt++;
        if(!armour[typ]
              || (funcall(call,armour[typ],"armour_class") <
                               funcall(call,a,"armour_class")))
          armour[typ]=a;
        break;
      default:
        armour[typ]=a;
    }
  }
  recalc_ac();

  if(funcall(call,a,"short")) {
    say(TName + " wears " + funcall(call,a,"query_name") + ".\n",0,TO,"");
    write("Ok.\n");
  }
  return 0;
}

int add_weight(int w) {
  if(ghost || ((w>=0) && (w+local_weight>query_str()+10) && !is_wizard))
    return 0;
  local_weight += w;
  return 1;
}

int can_put_and_get(string str) {
  return str != 0;
}

void zap_object(object ob) {
  funcall(call,ob, "attacked_by", this_object());
  say(TName + " summons a flash from the sky.\n",0,TO,
      "Suddenly a flash strikes "+
      funcall(call,ob,"query_name")+" out of the sky.\n");
  write("You summon a flash from the sky.\n");
  ob->misc_hit(1000000,7);
  write("There is a big clap of thunder.\n\n");
}

void stop_hunter(int silent) {
  hunter = 0;
  if (!silent) 
    tell_object(this_object(), "You are no longer hunted.\n");
}

object query_hunter() {
  return( hunter );
}

int add_spend_points(int p) {
  int i;

  if (p<0) {
    spend_points--;
    if (spend_points<0) 
      spend_points=0;
    return 1;
  }
  for (i=0;i<NUM_STATS;i++)
    if (stats[i] < funcall(call,GM,"query_levels",guild)) {
      spend_points++;
      break;
    }
  return 1;
}

string query_name() {
#if 0
    return "@@query_name_rdr:"+file_name(this_object())+"@@";
#else
    return query_name_rdr();
#endif
}

int query_value() { 
  return 0; 
}

int query_weight() { 
  return local_weight; 
}

void update_weight() {

  object *inv;
  int i, sz, all;

  inv = deep_inventory(this_object());
  all = 0;

  for (sz = sizeof(inv), i = 0; i < sz; i++)
    all = all + funcall(call,inv[i],"query_weight");

  local_weight = all;
}


int set_weight(int w) {
  if(w<1) 
    weight=1;
  else 
    weight=w;
  return weight;
}

/* USERDOC:
get_skill
Format: m1=get_skill(m2)
See also: change_skill.
Get certain values from the skill-database. Argument: m2 - what to get from 
the skill-database? -1 .. all skills (an array, format: array of string name, 
                          array of int level,array of int max_level,
                          array of int guildID)
        0-MAX_GUILD_ID .. all skills of this guild (array, format: 
                          array of string name,array of int level,
                          array of int max_level,array of int guildID)
              <string> .. skill with this name (mixed *, format: int level, 
                          int max_level, int guild-ID )
*/
mixed get_skill(mixed what) { 

  int idx, sz;
  mixed *ret,*hlp;

  if(!skills) 
    return;

  if(intp(what)) {
    if(what < -1 || what >= funcall(call,GM,"query_nog")) 
      return;
    ret=({ ({}),({}),({}),({}) });

    for(sz < sizeof(skills[0]),idx=0;idx<sz;idx++) {
      hlp=(mixed *)funcall(call,SM,"get_skill",skills[0][idx]);

      if(what == -1 || hlp[1]==what) {
        ret[0]+=({ hlp[0] });
        ret[1]+=({ skills[1][idx] });
        ret[2]+=({ skills[2][idx] });
        ret[3]+=({ hlp[1] });
      }
    } 
    return ret;
  } 
  else if(stringp(what)) {
    if(!(hlp=(mixed *)funcall(call,SM,"get_skill",what) )) 
      return;
    if((idx=member_array(hlp[0],skills[0]))==-1) 
      return;
    return ({ skills[1][idx] }) + ({ skills[2][idx] }) +
           ({ hlp[2] }); 
  } 
  else 
    return;
}

remove_skill_old(string name) {

  int idx;
  mixed *hlp;

  if(!(hlp=(mixed *)funcall(call,SM,"get_skill",name) )) 
    return -1;
  if((idx=member_array(hlp[0],skills[0]))==-1) 
    return -2;
  skills[0]=del_array(skills[0],idx);
  skills[1]=del_array(skills[1],idx);
  skills[2]=del_array(skills[2],idx);
  return 1;
}

/* USERDOC:
change_skill
Format: i1=change_skill(s,i2,i3,i4)
See also: get_skill.
Change a certain skill to 'value'. Arguments: s - the name of the skill, i2 - 
the new value of the skill, i3 - the maximum value of the skill (only used if 
the skill is new), guildID - the guild related to the skill. Returns: -1 if 
the skill has NOT been changed, 0 if it was a NEW skill or the old value if 
the change was OK. 
Specials: if a skill is liked to a special guild (ID > 0), it can only be 
          changed via the related guild-soul or room.
        - if the skill is not in the list jet, it will be automatically 
          inserted (but only if the skill already exists in the skill-master).
        - to add a new skill to the skill-master, a Lord or higher can do this
          at the adventurers-guild.
        - if the guild-ID is 0, the skill can be changed by every guild-soul 
          or room.
        - if the guild-ID is -1, the skill can be changed by everyone.
        - to change the max_value of a skill u have to give: the name, the 
          value has to be 0 and the max_value
*/
int change_skill(string name, int value, int max_value, int guildID) {

  int i,res;
  mixed *hlp;

  if(file_name(previous_object())!=GM) 
    return -1;

  if(!skills) 
    skills=({ ({}),({}),({}) });

  if(!(hlp=(mixed *)funcall(call,SM,"get_skill",name)))
    return -1;

  if(guildID!=hlp[2]) 
    return -1;

  if((i=member_array(hlp[0],skills[0]))==-1) { 
    if(max_value < value || hlp[0]==-1) 
      return -1;
    skills[0]+=({ hlp[0] });
    skills[1]+=({ value });
    skills[2]+=({ max_value });
    return 0;
  } 
  else {
    if(!value) {
      if(max_value) {
        skills[2][i]=max_value;
        if(skills[1][i]>max_value) 
          skills[1][i]=max_value;
      } 
      else 
        return -1;
    } 
    else {
      if(value>skills[2][i]) 
        return -1;
      res=skills[1][i];
      skills[1][i]=value;
      return res;
    }   
  }
  return -1;
}

// ----------------------- SKILLS --------------------------------------------
mapping get_all_skills() {
  return( nskills );
}

int nchange_skill( string sk, int value, int max_value ) {

  int i,res;

  if(!nskills) 
    nskills=([]);
  if ( !stringp(sk) ) 
    return -1;
  if( !(SKILL_MASTER->get_skill(sk)) )
    return( -1 );
  if ( nskills[sk] )
    return( -1 );
  if ( value > max_value )
    value = max_value;
  nskills[sk] = ({value, max_value});
  return( 1 );
}

int remove_skill( string sk ) {
  if ( sk && nskills[sk] ) {
    nskills = m_delete( nskills, sk );
    return( 1 );
  }
  return( 0 );
}

int get_skill_value( string sk ) {
  if ( nskills && sk && nskills[sk] )
    return( nskills[sk][0] );
  return( -1 );
}

int set_skill_value( string sk, int value ) {
  if ( !sk || !nskills[sk] )
    return( -1 );
  if ( value > nskills[sk][1] ) value = nskills[sk][1];
  return( nskills[sk][0] = value );
}

int get_skill_max( string sk ) {
  if ( nskills && sk && nskills[sk] )
    return( nskills[sk][1] );
  return( -1 );
}

int set_skill_max( string sk, int value ) {
  if ( !sk || !nskills[sk] || value < 1 )
    return( -1 );
  if ( nskills[sk][0] > value ) nskills[sk][0] = value;
  return( nskills[sk][1] = value );
}

// ----------------------- SPELLS -----------------------------------------
mixed get_spell(mixed what) {

  int idx;

  if(!spells) 
    return;
  if( intp(what) && what == -1 ) {
    return( spells );
  } 
  else if(stringp(what)) {
    if( (idx=member_array(what,spells[0])) ==-1) 
      return;
    return ({ spells[0][idx] }) + ({ spells[1][idx] }) +
           ({ spells[2][idx] }) + ({ spells[3][idx] }); 
  }  
  else 
    return;
}

int change_spell(string name, int value, int max_value, int relTime) {

  int i,res;
  string fn;

  if(!spells) 
    spells=({ ({}),({}),({}),({}), });

  if ( !stringp(name) ) 
    return -1;

  if(!(fn=(string)funcall(call,SPELL_MASTER,"get_spell",name)))
    return -1;

  if ( member_array( name, spells[0] ) >= 0 )    // already has the spell
    return( -1 );

  if ( value > max_value ) value = max_value;

  spells[0]+=({ name });
  spells[1]+=({ value });
  spells[2]+=({ max_value });
  spells[3]+=({ relTime });

  return( 1 );
}

void set_spell_skill( string spell_name, int sk ) {

  int idx;

  if ( sk > -1 && spells )
    if ( (idx=member_array( spell_name, spells[0] )) > -1 )
      if ( spells[2][idx] >= sk )
        spells[1][idx] = sk;
}

void set_spell_maxskill( string spell_name, int sk ) {

  int idx;

  if ( sk > -1 && spells )
    if ( (idx=member_array( spell_name, spells[0] )) > -1 ) {
      spells[2][idx] = sk;
      if ( sk < spells[1][idx] )
        spells[1][idx] = sk;
    }
}

void set_spell_speed( string spell_name, int sp ) {

   int idx;

   if ( sp > -2 && spells )
     if ( (idx=member_array( spell_name, spells[0] )) > -1 )
       spells[3][idx] = sp;
}

int get_spell_skill( string spell_name ) {

  int idx;

  if ( spells && (idx=member_array(spell_name,spells[0])) > -1 )
    return( spells[1][idx] );
  return( -1 );
}

int get_spell_maxskill( string spell_name ) {
  int idx;

  if ( spells && (idx=member_array(spell_name,spells[0])) > -1 )
    return( spells[2][idx] );
  return( -1 );
}

int get_spell_speed( string spell_name ) {
  int idx;

  if ( spells && (idx=member_array(spell_name,spells[0])) > -1 )
    return( spells[3][idx] );
  return( -2 );
}

/* USERDOC:
move_player
Format: move_player(s[,o][,r][,i])
Example: move_player("X#room/church")
This routine is called from objects that moves the player. Special: direction 
"X" means teleport. s is "how#where". o is an object to move the player to. If
the second argument exists, then the first argument is taken as the movement 
message only.
If r is non-zero the 'dir_dest' is displayed without msgout.
If you want you can specify a special income-message(i) too.
*/
mixed move_player(mixed  dir_dest,
                  mixed  optional_dest_ob,
                  mixed  raw,
                  string income_msg) {

  string dir,who,junk,pos, short_str, msg;
  mixed tmp, dest;
  object *items, ob, prev, lastroom;
  int get_rid,is_light,i,amount;

// if we havn't got an optional_dest_ob we have to get destination out of
// the dir_dest
  if (!optional_dest_ob) {
    if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
      tell_object(this_object(), "Move to bad dir/dest\n");
      return;
    }
  } 
  else {
    dir = dir_dest;
    dest = optional_dest_ob;
  }
  lastroom=environment();

  if (attacker_ob && present(attacker_ob)) {
    hunter = attacker_ob;
    tell_object(this_object(),"You are now hunted by " +
                funcall(call,attacker_ob,"query_name")+".\n");
    if ( is_npc )
      this_object()->add_hunted( attacker_ob );
    attacker_ob = 0;
  }
  is_light = set_light(0);
  if(is_light < 0)
    is_light = 0;
  if(is_light && (!is_sneaking || dir == "X")) {
    if (raw) {
      if (ghost)
        say(NAME_OF_GHOST+" "+dir+"\n",this_object());
      else
        say(TName+" "+dir+"\n",0,this_object(),"");
    }
    else {
      if (!msgout)
        msgout = "leaves";
      if (ghost) 
        say(NAME_OF_GHOST+" "+msgout+" "+dir+".\n",this_object());
      else if (dir == "X") 
        say(TName+" "+mmsgout+".\n",0,this_object(),"");
      else 
        say(TName+" "+msgout+" "+dir+".\n",0,this_object(),"");
    }
  }
  move_object(this_object(), dest);

  abort_concentration();
  if ( is_sneaking > 0 ) is_sneaking--;
  is_hidden = 0;

  tmp=dest;

  if(stringp(tmp)) 
    tmp=find_object(tmp);
  dest=tmp;
  if(environment(this_object())!=tmp) 
    return;

  is_light = set_light(0);

  if(is_light < 0)
    is_light = 0;

  if (!is_npc && level>=L_APPR) {
    tell_object(this_object(), "/" + file_name(dest) + "\n");
  }
  if(is_light && (!is_sneaking || dir == "X")) {
    if (!msgin) msgin = "arrives";
    if (!mmsgin) mmsgin = "arrives";
    if (dir == "X") tmp=mmsgin+".";
    else            tmp = msgin+".";

    if (income_msg) 
      tmp=income_msg;
    if (ghost) 
      say(NAME_OF_GHOST+" "+tmp+"\n");
    else {
      say(TName+" "+tmp+"\n",0,this_object(),"");
    };
  }

/* ----- this should be managed by the init of the mob
  ------ if not, tell me
  if (is_npc && hunted && present(hunted))
    attack_object(hunted);
*/

  if (!interactive())
    return;

  if (is_npc) {            // only valid at possessed, do we really need it ?
    write(funcall(call,"environment","short")+".\n");
    items=all_inventory(environment());
    map_array(items,"list_inv",this_object());
  }
  tmp=last_cmd; 

  if(member_array("room/room.c",inherit_list(dest))==-1) {
    log_file("NONSTD_ROOM",file_name(dest)+" - "+
             name+"\n");
  }
  if(dest->test_darkness()<1) {
    write("It's pitch black.\n");
  }
  else funcall(call,this_object(),"mylook",brief);

// leaving the arena
  if ( funcall(call,lastroom,"query_arena") ) {
    if ( !funcall(call,environment(this_object()),"query_arena") ) {
      if ( ARENA->contestant_left( this_object() ) )
        ARENA->arena_shout( cap_name+" cowardly left the arena !!!\n" );
    }
  }

// the groupfollow
  if(follow_obj) {
    rep_follow_obj();
    get_rid=0;
    if((prev=previous_object())
           && (prev==lastroom || funcall(call,prev,"id","door"))) { 
// made faster
      i = sizeof(follow_obj);

      while(i) { 
        i--;
        if(follow_obj[i]==attacker_ob) {
          command("follow",attacker_ob);
          continue;
        }
        if(funcall(call,follow_obj[i],"query_linkdeath")) 
          continue;
        if(environment(follow_obj[i])==lastroom) {
          if(follow_obj[i]==rid_whom) {
            tell_object(this_object(),"You try to shake off "
                          + funcall(call,rid_whom,"query_name")+".\n");
            if(random(100) < 80+is_invis*30) 
              get_rid=1;
            else {
              tell_object(follow_obj[i],query_name()
                      + " tried to shake you off, but you "
                        + "managed to follow "+query_objective()
                        + (dir ? " "+dir+"." : ".")+"\n");
              command(tmp,follow_obj[i]);
            }
          } 
          else {
            tell_object(follow_obj[i],"You follow "+query_name()
                      + (dir ? " "+dir+"." : ".")+"\n");
            command(tmp,follow_obj[i]);
          }
        } /* if(environment(follow_obj[i])==lastroom) */
      } /* end loop */
      if(get_rid) 
        command("follow",rid_whom);
    } 
    else {
      i = sizeof(follow_obj);
      while(i) {
        i--;
        if(follow_obj[i]
                && environment(follow_obj[i])==lastroom) 
          tell_object(follow_obj[i],"You've lost your leader !\n");
      }
    }
  }
}

void list_inv(object ob) 
{ 
    write(funcall(call,ob,"short")+".\n"); 
}

/* USERDOC:
query_followers
Format: o=query_followers()
See also: query_follow_whom, query_rid_whom.
Returns an array with objects following this living.
*/
mixed query_followers() { 
  rep_follow_obj();
  return follow_obj; 
}

/* USERDOC:
query_follow_whom
Format: o=query_follow_whom()
See also: query_followers, query_rid_whom.
Returns the object this living is following.
*/
object query_follow_whom() { 
  return follow_whom; 
}

/* USERDOC:
query_rid_whom
Format: o=query_rid_whom()
See also: query_followers,query_follow_whom.
Returns the object that this living is trying to get rid of.
*/
object query_rid_whom() { 
  return rid_whom; 
}

/* USERDOC:
set_follower
Example: this_player()->set_follower(this_object())
Format: set_follower(o)
See also: query_followers,query_follow_whom,rem_follower.
Sets an object as following this living.
*/
int set_follower(object f) {

  if(!follow_obj) 
    follow_obj=({});

  rep_follow_obj();

  if(chk_follow(this_object(),f)) 
    return 1;
  rem_follower(f);
  follow_obj+=({ f });
  return 1;
}

/* USERDOC:
rem_follower
Format: rem_follower(o)
Example: this_player()->rem_follower(this_object())
See also: query_followers,query_follow_whom,set_follower.
Removes an object as following this living.
*/
void rem_follower(object f) {
  int idx;
  rep_follow_obj();
  if((idx=member_array(f,follow_obj))!=-1) {
    follow_obj=del_array(follow_obj,idx);
    if(f==rid_whom) 
      rid_whom=0;
  }
}

/* USERDOC:
hold
Format: hold(o,i)
Example: this_object()->hold(0,10)
This function prevents this living to fight for i seconds. o is an object in
which hold_end() is called with this living as argument when the hold ends.
*/
int hold(object caller,int time) {

  int time_to_go;

  if (funcall(call,this_object(),"immunity_paralyze")) 
    return 0;
  if(hold_flag) 
    time_to_go=remove_call_out("de_hold");
  hold_flag=1;
  time_to_go = (time_to_go < time ? time : time_to_go);
  if(interactive(this_object()))
    disable_interactive(this_object(),time_to_go*2);
  call_out("de_hold",time_to_go,caller);
  return 1;
}

/* USERDOC:
is_invis_for
Format: i=is_invis_for(o)
Checks, if this living is invis for the checker o. 0 is returned if it isn't. 
*/
nomask int is_invis_for(object checker) {

  int chk_level, can_see;

  if(checker==this_object()) return 0;
  if( !(this_object()->query_invis()) && !(this_object()->query_hidden()) )
    return 0;

// ----- invis
  if ( this_object()->query_immortal() ) {
    chk_level = checker->query_level();
    if ( checker->query_npc() ) chk_level = 1;
    can_see = ( chk_level > this_object()->query_invis() );
  }
  else {
    if ( this_object()->query_invis() ) {
      if ( checker->detect_invis() || checker->query_immortal() )
        can_see = 1;
      else can_see = 0;
    }
    else
      can_see = 1;
  }
// ----- hidden
  if ( can_see ) {
    if ( this_object()->query_hidden() ) {
      if ( checker->detect_hidden() || checker->query_immortal() )
        can_see = 1;
      else can_see = 0;
    }
  }

  return( !can_see );
/*
    if(funcall(call,checker,"detect_invis") && 
      !funcall(call,this_object(),"query_immortal"))
        return 0;
    chk_level = checker->query_level();
    if ( checker->query_npc() ) chk_level = 1;
    return( chk_level <= this_object()->query_invis() );
*/
}

int  query_hidden()    { return( is_hidden ); }
void hide()            { is_hidden = 1; }
void unhide()          { is_hidden = 0; }
int  query_sneaking()  { return( is_sneaking ); }
void sneak()           { is_sneaking = 111; }
void stop_sneak()      { is_sneaking = 0; }

// this has to be varargs !!!
private varargs mixed _hit_player(int dam,int kind,mixed elem);

nomask int hit_by_spell(int dam) {

  if(file_name(previous_object())[0..11]!="spells/aggr/") {
    log_file("ILLEGAL",ctime(time())+"\n"
        "hit_by_spell called by "+this_player()->query_real_name()+"\n"+
        "with "+file_name(previous_object())+"\n"+
        "Creator: "+ (creator(previous_object()) ?
                      creator(previous_object()) : "root")+
        "\nDAMAGE: "+dam+"\n");
        return( 0 );
  }
  dam = _hit_player(dam,8,0);
  if ( this_player() )
    this_player()->add_exp( dam );
  return( dam );
}

nomask int hit_by_ability(int dam,int kind) {

  if(file_name(previous_object())[0..14]!="abilities/aggr/") {
    log_file("ILLEGAL",ctime(time())+"\n"
        "hit_by_spell called by "+this_player()->query_real_name()+"\n"+
        "with "+file_name(previous_object())+"\n"+
        "Creator: "+ (creator(previous_object()) ?
                      creator(previous_object()) : "root")+
        "\nDAMAGE: "+dam+"\n");
        return( 0 );
  }
  dam = _hit_player(dam,kind,0);
  if ( this_player() )
    this_player()->add_exp( dam );
  return( dam );
}

/* USERDOC:
hit_player
Format: hit_player(i1[,i2])
Example: hit_player(10)
See also: reduce_hit_point.
This function is called from other players when they want to make damage to 
us. We return how much damage we received, which will change the attackers 
score. This routine is probably called from heart_beat() from another player.
The second argument is not necessary, and determines the kind of the strike. 
(0 .. AC  (eg normal hit),  !! here is bit dex involved !!
 1 .. str (some spells eg. 'entangle'),
 2 .. dex (eg. falls or certain traps),
 3 .. con (eg. poisons),
 4 .. int (some spells eg. illusion or charm),
 5 .. wis (attack spells, traps ...),
 6 .. chr (*shrug* maybe backstab?),
 7 .. undefined damage(no resistance!) )

elem: damge - element .. eg ({ 2, 12 }) for electric/magic == lightning spell
 0  .. undefined
 1  .. heat
 2  .. electric
 3  .. cold
 4  .. acid
 5  .. energy
 6  .. drain
 7  .. touch
 8  .. petrify
 9  .. poison
 10 .. breath
 11 .. deathmagic
 12 .. magic
 13 .. pierce
 14 .. slash
 15 .. crush

the elem variable is good for use in shadows (eg. Prot from Fire Spell)
ATTENTION: this function may only be called by system files !!!!!!
*/
varargs mixed hit_player(int dam,int kind,mixed elem) {
  return _hit_player(dam,kind,elem);
}

// this IS necessary
private varargs mixed _hit_player(int dam,int kind,mixed elem) {

  object room,tp;

  if (this_player())
    last_attacker = this_player();

  if(kind>8 || kind<0) 
    kind=0;

  if (hold_flag) {
    if (!attacker_ob || environment()!= environment(attacker_ob) )
      set_heart_beat(1);
    else
      set_heart_beat(0);
  }
  else
    set_heart_beat(1);

  if (!attacker_ob && last_attacker != this_object()) {
    attacker_ob = last_attacker;
    funcall(call,attacker_ob,"attack_object",this_object());
  }

  if ( this_player() && this_player()!=this_object() 
         && !(this_player()->allowed_attack(this_object())) ) {
    tell_object(this_object(),funcall(call,this_player(),"query_name") +
                              " tried to attack you!\n");
    write(query_name()+" is protected by the Gods !\n");
    stop_fight();
    stop_fight();
    stop_hunter(1);
    this_player()->stop_fight();
    this_player()->stop_fight();
    this_player()->stop_hunter(1);

    return( 0 );
  }

  return( misc_hit( dam, kind, elem ) );
}

// interface same as in hit_player()
nomask int misc_hit( int dam, int kind, mixed elem ) {

  int armour_bonus;

  if ( dam < 0 || ghost || dead )
    return( 0 );

  switch(kind) {
    case 0:  
      if (this_player() &&
        funcall(call,this_object(),"dodge_bon",this_player()) && !hold_flag) {
        dam = 0;
      }
      else {
        armour_bonus = 2 * funcall(call,TO,"query_ac");
        if (armour_bonus > 60)  
          armour_bonus = 60;
        dam =  (dam * 100 - (dam * armour_bonus))/100; 
      }
      break;
    case 1..4: break;
    case 5:    
      if (interactive(this_object()))
        dam -= random( (query_int() + query_wis()) /5); 
      else 
        dam -= random( (query_int() + query_wis()) /10); 
      break;
    case 6:   
      dam -= random( (query_con()/8) ); 
      break;
    case 7:    
      break;
    case 8:    
      break;
    default: 
      dam -= random(this_object()->query_ac());
      break;
  }

  if (dam <= 0)
    return( 0 );
  if (dam > hit_point+1)
    dam = hit_point+1;

  hit_point -= dam;

  if ( hit_point < 0 )
    if ( !do_die( last_attacker ) )
      dam = 0;

  if(this_player())
    this_player()->add_exp(dam);
  return( dam );
}

// <- 1 if dead, 0 if not dead
private int do_die( object killer ) {

  object corpse;
  
// ----- linkdead ----- 
  if (!is_npc && !query_ip_number(this_object())) {
    write(cap_name + " is not here. You cannot kill a player who is " +
          "not logged in.\n");
    hit_point = 20;
    stop_fight();
    if (this_player())
      this_player()->stop_fight();
    return( 0 );
  }

   // ----- a wizard -----
  if (!is_npc && is_wizard ) {
    tell_object(this_object(), "Your wizardhood protects you from death.\n");
    tell_object(this_player(), CName + "'s wizardhood protected " +
                               query_objective() + " from death.\n");
    if( this_player() ) {
      this_player()->stop_fight();
      this_player()->stop_hunter(1);
    }
    hit_point = 1;
    return 0;
  }

// ----- player is killed -----
  if (!is_npc && killer && killer != this_object() && level > 1) {
    int      lvl,msg,wizard, wc;
    object   wp;
    string   text, pronoun_of_attacker, name_of_attacker;
 
    pronoun_of_attacker = killer->query_pronoun();
    name_of_attacker    = killer->query_real_name();
    if ( !name_of_attacker )
      name_of_attacker  = killer->query_name();
    else 
      name_of_attacker  = capitalize(name_of_attacker);
 
    if ( !(environment(this_object())->query_arena()) ) {   // not the arena
      msg = random(4);
 
      switch(msg) {
        case 0:
          if (pronoun_of_attacker=="they")
            text=" howl ";
          else
            text=" howls ";
          text += "with pleasure as " + pronoun_of_attacker + " kills " +
                          cap_name + ".\n";
          shout(name_of_attacker+text);
          break;
        case 1:
          shout(name_of_attacker+" munches on the dead body of " +
                cap_name+".\n");
          break;
        case 2:
          if (pronoun_of_attacker=="they") text=" dance ";
          else text=" dances ";
          text+= "around the dead body of " + cap_name+".\n";
          shout(name_of_attacker+text);
          break;
        case 3:
          if (pronoun_of_attacker=="they") text=" fart ";
          else text=" farts ";
          text+="rudely as "+pronoun_of_attacker+" sent " +
                cap_name+" to "+query_possessive()+" creator.\n";
          shout(name_of_attacker+text);
          break;
      } //endswitch
 
      if ( !(killer->query_npc()) ) {             // player killed by player
        lvl = killer->query_level();
        wizard = killer->query_immortal();
        wp = killer->query_wielded_weapon();
        wc = killer->query_wc();
 
        if (!wizard) shout("PLAYER killed by another PLAYER !\n");
        else if (lvl<L_ARCH) shout("PLAYER killed by a WIZARD !\n");
        else if (lvl<L_GOD) shout("PLAYER killed by an ARCHWIZARD !\n");
        else shout("PLAYER killed by GOD !\n");
 
        if (wp)
          log_file( "KILLS.PLAYER", ctime() + " " + name+"("+level+") killed by "+
                    name_of_attacker+
                    "("+lvl+") with "+creator(wp)+" "+file_name(wp)+"\n");
        else 
          log_file( "KILLS.PLAYER", ctime() + " " + name+"("+level+") killed by "+

                    name_of_attacker+ "("+lvl+")\n");
      }
    }
  }

// ----- now handle the death -----
  dead = 1;
  ghost = 1;

  hunter = 0;
  say(cap_name + " died.\n",this_object());
  write( cap_name + " died.\n" );
  if ( !interactive(this_object())
                || !environment(this_object())
                || !(environment(this_object())->query_arena()) ) {
    experience =  (experience / 3) * 2;
  }
  hit_point = 10;

  if ( attacker_ob && !(environment()->query_arena()) ) {
    int    divide,i,levs, sz;
    object *gr_list;

    gr_list=funcall(call,attacker_ob,"grmems_in_room");

    if (!sizeof(gr_list)) 
      gr_list = ({attacker_ob,});
    for(sz = sizeof(gr_list), i = levs = 0 ; i < sz ; i++) 
      levs += gr_list[i]->query_level() + gr_list[i]->query_legend_level();
    for(sz = sizeof(gr_list), i = 0 ; i < sz ; i++) {
      if(funcall(call,gr_list[i], "query_grouped"))
        tell_object(gr_list[i], "You get your share of experience.\n");
      if (gr_list[i]->query_quest_points() < QR->query_total_weight())
        divide = (180 - ((140 * gr_list[i]->query_quest_points())
                   / QR->query_total_weight())) * levs;
      else
        divide = 40 * levs; // just shortened the expression
      gr_list[i]->add_exp( (experience * 
                (gr_list[i]->query_level() + gr_list[i]->query_legend_leve()))
                / divide);
    }
    alignment = ADJ_ALIGNMENT(alignment);
    attacker_ob->add_alignment(alignment);
  }

// ----- and now get a corpse -----
  if(is_npc) {                               // monster
    if ( !(this_object()->second_life(this_object())) ) {
      if ( !(this_object()->set_corpse()) ) {
        corpse = clone_object("obj/corpse");
        corpse->set_name(name);
        corpse->set_race(query_race()); 
        corpse->set_weight(weight);
        transfer_all_to(corpse);
        move_object(corpse, environment(this_object()));
        destruct(this_object());
      }
    }
  } 
  else {                            // player
    corpse = clone_object("obj/corpse");
    funcall(call,corpse, "set_name",   name);
    funcall(call,corpse, "set_race",   "query_race"); 
    funcall(call,corpse, "set_weight", weight);
    move_object(corpse,  environment(this_object()));
    if ( funcall(call,environment(this_object()), "query_arena") ) {
      write( "You DEFEATED " + cap_name + ".\n" );
      tell_object( this_object(), "YOU HAVE BEEN DEFEATED !!!\n" );
      ARENA->arena_shout( cap_name + " hath been defeated by " +
             capitalize(TP->query_real_name()) + " !!!\n" );
      ARENA->leave_arena( this_object() );
      hit_point    = max_hp;
      spell_points = max_sp;
      dead = ghost = 0;      // undo it !
    }
    else {
      transfer_all_to(corpse);
      if (!funcall(call,this_object(), "second_life", 0)) 
        destruct(this_object());
      save_object("/p/" + (explode(name,"")[0]) + "/" + name);
    }
  }

  return( 1 );
}

/* USERDOC:
transfer_all_to
Format: transfer_all_to(o)
Example: transfer_all_to(this_player())
This function moves all objects,including money,from this living to o. This
is used for the corpse, but could be used for other purposes as well.
*/
void transfer_all_to(mixed dest) {
  object ob;
  object next_ob;

  ob = first_inventory(this_object());

  while(ob) {
    next_ob = next_inventory(ob);
    if (!funcall(call,ob, "drop", 1) && ob)
      move_object(ob, dest);
    ob = next_ob;
  }
  local_weight = 0;
  if (money == 0)
    return;
  ob = clone_object("obj/money");
  funcall(call,ob, "set_money", money);
  move_object(ob, dest);
  money = 0;
}

/* USERDOC:
query_short_name
Format: s=query_short_name
See also: query_real_name.
This function returns the shortest version of a printable name, either the
name of the ghost, or the name of the player.
*/
string query_short_name() {
  if (ghost)
    return NAME_OF_GHOST;
  return capitalize(name);
}

/* USERDOC:
query_real_name
Format: s=query_real_name
See also: query_short_name.
This function returns the name of the character, without any modifications in
lower_case. This is one of the few parameters of a character that will NEVER
change.
*/
nomask string query_real_name() { 
  return name; 
}

/* USERDOC:
set_smell
Format: set_smell(s)
Example: set_smell("This person stinks.")
See also: query_smell.
This sets the smell of this player. A \n is not needed, a '.', '!' or '?' is.
The smell can be smelled by other players.
*/
void set_smell(string s) {
  my_smell=s;
}

/* USERDOC:
query_smell
Format: s=query_smell()
See also: set_smell.
This returns the last smell set by set_smell.
*/
string query_smell() {
  return my_smell;
}

/* USERDOC:
query_alignment
Format: i=query_alignment()
See also: query_al_string.
This returns the alignment of the living. This is an integer. Negative
indicates the living is evil, and a positive value indicates the living is
good.
*/
int query_alignment() {
  return alignment;
}

/* USERDOC:
query_al_string
Format: s=query_al_string()
See also: query_alignment.
This function returns a string that indicates the alignment of this living.
This string can be "saintly", "good", "nice", "neutral", "nasty", "evil" or
"demonic".
*/
string query_al_string() {

  if (alignment > KILL_NEUTRAL_ALIGNMENT * 100) return "saintly"; 
  else if (alignment > KILL_NEUTRAL_ALIGNMENT * 20) return "good";
  else if (alignment > KILL_NEUTRAL_ALIGNMENT * 4) return "nice";
  else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 4) return "neutral";
  else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 20) return "nasty";
  else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 100) return "evil";
  return "demonic";
}

/* USERDOC:
set_no_fight
Format: set_no_fight(i)
Example: set_no_fight(1)
See also: query_no_fight.
If this function is called with i is unequal to 0, and the living is a monster,
then the monster won't fight when attacked.
*/
void set_no_fight(int i) { 
  if(is_npc) 
    no_fight=i; 
}

/* USERDOC:
query_no_fight
Format: i=query_no_fight()
See also: set_no_fight.
This function returns 0 if the monster will fight when provoked.
*/
int query_no_fight() { 
  return no_fight; 
}

/* USERDOC:
attacked_by
Format: attacked_by(o)
Example: attacked_by(this_player())
See also: change_attacker.
This routine is called when we are attacked by a player. o is the thing
attacking the living, and will probably be attacked back.
*/
int attacked_by(object ob) {
  if (!attacker_ob) {
    attacker_ob=ob;
    return( 1 );
  }
  return( 0 );
}

/* USERDOC:
change_attacker
Format: change_attacker(o)
Example: change_attacker(this_player())
See also: attacked_by.
This function works like attacked_by(), but the prime victim of the revenge of
the living will be o.
*/
void change_attacker(object ob) {
  attacker_ob=ob;
  ob->attacked_by( this_object() );
  set_heart_beat(1);
}

/* USERDOC:
show_stats
Format: show_stats()
This shows all information about this living.
*/
void show_stats() {
  int i,j, sz;
  string msg, *h;

  msg=(short() + " (" + query_gender_string() + " " +
        query_race() +") ("+sizes[real_size]+")\n"); 
  msg+=("-----------------------------------------------------\n");
  msg+=("Level : " + level + " (" + this_object()->query_legend_level() +
        ")\tExperience     : "+ experience + "\tAlign : " + alignment + "\n");
  msg+=("Coins : " + money + "\tCarried weight : " + local_weight +
        "(" + (Str+10) + ")\n");
  msg+=("HP    : "+hit_point+ "  \tof "+max_hp+"\n");
  msg+=("SP    : "+spell_points+"  \tof "+Max_sp+"\n");
  msg+= sprintf( "Str   : %3d (%3d)  Dex: %3d (%3d)  Con: %3d (%3d)\n",
        query_str(),query_r_stats(0),query_dex(),query_r_stats(1),
        query_con(),query_r_stats(2) );
  msg+= sprintf( "Int   : %3d (%3d)  Wis: %3d (%3d)  Chr: %3d (%3d)\n",
        query_int(),query_r_stats(3),query_wis(),query_r_stats(4),
        query_chr(),query_r_stats(5) );
  msg+=("-----------------------------------------------------\n");
  if(this_object()->query_immortal()) msg+=("Ranking: Immortal\n");
  else if(this_object()->query_testchar())
    msg+=("Ranking: Testchar (" + this_object()->query_testchar() + ")\n");
  else msg+=("Ranking: Mortal\n");
  msg+=("Guild         : "+guild+" "+GM->query_name(guild)+"\n");
  recalc_ac();      /* correct rings and other armours and recalc the ac */
  msg+=("Armourclass   : "+TO->query_ac()+"   natural: "+natural_ac+"\n");
  if(arm_types && armour_class) {
    msg+=("----- Armours -----");
    for(sz=sizeof(arm_types),i=0;i<sz;i++) {
      if(armour[i]) {
        msg+=("\n"+arm_types[i]);
        msg+=(":\t ");
        msg+=(funcall(call,armour[i],"query_name"));
        msg+=("\t ac: ");
        msg+=(funcall(call,armour[i],"armour_class"));
      }
    }
    if(ring_cnt>0) {
      msg+=("\nRings:\n  ");
      for(i=0;i<ring_cnt-1;i++)
        if(rings[i]) msg+=(funcall(call,rings[i],"query_name")+" \t"); 
        if(rings[i]) msg+=(funcall(call,rings[i],"query_name"));
    }
    if(other_cnt>0) {
      msg+=("\nOthers:\n  ");
      for(i=0;i<other_cnt-1;i++)
        if(others[i])
          msg+=(funcall(call,others[i],"query_name")+" ("+
               funcall(call,others[i],"query_type")+") \t");
        if(others[i])
          msg+=(funcall(call,others[i],"query_name")+" ("+
               funcall(call,others[i],"query_type")+")");
    }
    msg+=("\n-------------------\n");
  }
  msg+=( "---hands---\n" );
  msg+=("Natural WC    : "+natural_wc+"\n");
  msg+=( "number of arms: " + number_of_arms + "\n" );
  i = 0;
  for(sz=sizeof(hands),i=0;i<sz;i++) {
    if ( hands[i] ) {
      msg+=(funcall(call,hands[i],"short"));
      if ( funcall(call,hands[i],"query_weapon") )
        msg+=(" with wc "+ funcall(call,hands[i],"weapon_class"));
      msg+=( "\n" );  
    }
    else 
      msg+=( "nothing holding\n" );
  }
  msg+=( "-----------\n" );

  if (attacker_ob) {
    msg+=("Attacked by   : " + funcall(call,attacker_ob,"query_name")+"\n");
  }
  h = funcall( call, this_object(), "get_hunted" );
  if ( h && (i=sizeof(h)) > 0 ) {
    msg += "Hunted:       : ";
    for ( --i; i >= 0; i-- ) {
      msg += h[i]->query_real_name()+", ";
    }
    msg += "\n";
  }
  show_age();
  if(dead) 
    msg+=("Current status: ghost\n");
  if(is_wizard) 
    msg+=("Ranking as wizard.\n");
  this_interactive()->more_string(msg);
}

void show_quests() {
  int i,j,tmp,sz;
  string *quests,msg;

#define OUT_WIDTH 60
  msg="Solved Quests:\n";
  if(!funcall(call,this_object(),"query_quests")) 
    msg+=("none.\n");
  else {
    quests=explode(funcall(call,this_object(),"query_quests"),"#");
    tmp=strlen(quests[0]);
    for(sz=sizeof(quests),i=1;i<sz;i++) 
      if(tmp<strlen(quests[i])) 
        tmp=strlen(quests[i]);
    j=0;
    for(sz=sizeof(quests),i=0;i<sz;i++) { 
      if(j+tmp>OUT_WIDTH-1) { 
        j=0; 
        msg+=("\n"); 
      }
      j+=tmp; msg+=(quests[i]);
      msg+=(extract(
            "                                                            ",
           strlen(quests[i]),tmp));
    }
    msg+=("\n");
  }
  this_player()->more_string( msg );
}

/* USERDOC:
set_n_ac
Format: set_n_ac(i)
Example: set_n_ac(5)
See also: set_n_wc, query_n_ac.
This function sets the natural armourclass of the living. This AC is added to
the armourclass of the armour the living is wearing.
*/

void set_n_ac(int ac) {
  natural_ac=ac;
  recalc_ac();
}

/* USERDOC:
set_n_wc
Format: set_n_wc(i)
Example: set_n_wc(10)
See also: set_n_ac
This function sets the natural weaponclass of the living. This WC is added to
the weaponclass of the weapon the living is wielding.
*/

void set_n_wc(int wc) {
  natural_wc=wc;
}

/* USERDOC:
query_n_ac
Format: i=query_n_ac()
See also: set_n_ac.
This function returns the natural armourclass of this living.
*/
int query_n_ac() { 
  return natural_ac; 
}

/* USERDOC:
query_level
Format: i=query_level()
This function returns the level of this living.
*/
nomask int query_level() {
  if(interactive(this_object()))
    "/players/sauron/secure/sys/level_list"->add(file_name(previous_object()));
  return level;
}

/* USERDOC:
query_attack
Format: query_attack()
Example: query_attack()
This function returns the object attacking this living if o is not supplied,
otherwise o is returned if o is attacking this living.
*/
varargs object query_attack( object ob ) {

  object *hunted;

  if ( !ob ) return attacker_ob;

  if ( ob ) {
    if ( attacker_ob == ob ) return( ob );
    if ( ob->query_hunter() == this_object() ) return( ob );
    hunted = this_object()->get_hunted();
    if ( hunted && member_array( ob, hunted ) > -1 ) return( ob );
  }

  return( 0 );
}

/* USERDOC:
drop_all_money
Format: drop_all_money(i)
This function drops all the money of the player. If i is unequal to 0 then
texts will be displayed that this occurs.
*/
void drop_all_money(int verbose) {

  object mon;

  if (money == 0)
    return;
  mon = clone_object("obj/money");
  funcall(call,mon, "set_money", money);
  move_object(mon, environment());

  if (verbose) {
    say(TName + " drops " + money + " gold coins.\n",0,TO,
        IName + " drops " + money + " gold coins.\n");
    tell_object(this_object(), "You drop " + money + " gold coins.\n");
  }
  money = 0;
}

/* USERDOC:
set_number_of_arms
Format: set_number_of_arms(i)
Example: set_number_of_arms(2)
See also: query_number_of_arms.
This function sets the number of arms of the living. This can be used to wield
multiple weapons.
*/
void set_number_of_arms(int c)  {

  object *tmp;

  if ( c <= number_of_arms )               // not possible at the moment
    return( 0 );

  tmp = allocate( c - number_of_arms );
  hands += tmp;
  number_of_arms = c;
}

/* USERDOC:
query_number_of_arms
Format: i=query_number_of_arms()
See also: set_number_of_arms.
This function returns the number of arms of this living.
*/
int query_number_of_arms() { 
  return number_of_arms; 
}

/* USERDOC:
query_hands_free
Format: i=query_hands_free()
See also: set_number_of_arms.
This function checks if there is still a hand free to wield a weapon in.
*/
int query_hands_free() {
  int i, count;

  count = 0;
  for ( i = 0; i < number_of_arms; i++ ) {
    if ( !(hands[i]) )
      count++;
  }

  return( count );
}

/* USERDOC:
where_holding
Format: i=where_holding(o)
See also: get_hand_name, query_hands_free.
This function returns in which hand o is held. The returned value is an array.
*/

mixed where_holding(object ob) {
  int i, *where;

  where = ({});
  for ( i = 0; i < number_of_arms; i++ )
    if ( hands[i] == ob ) where += ({ i });
  return( where );
}

/* USERDOC:
get_hand_name
Format: s=get_hand_name(i)
See also: where_holding.
This function returns the name of the hand number i.
*/
string get_hand_name(int h) {
  switch( h ) {
    case 0:
      return( "right" );
    case 1:
      return( "left" );
  }
  return( "other" );
}

/* USERDOC:
query_wielded
Format: o=query_wielded()
See also: where_holding.
This function returns the weapon held in hand 0, if there is one there.
*/
mixed query_wielded() { 
  if ( hands && sizeof(hands) && hands[0] && hands[0]->query_weapon() ) 
    return( hands[0] ); 
}

/* USERDOC:
query_armour
Format: o=query_armour()
See also: query_others, query_rings.
This function returns an array with all armours that count for ac in it. 0 is
returned if there are no such armours.
*/
mixed query_armour() { 
  return armour; 
}

/* USERDOC:
query_others
Format: o=query_others()
See also: query_armour, query_rings.
This function returns an array with all other armours in it, the ones that are
worn but do not count to ac.
*/
mixed query_others() { 
  return others; 
}

/* USERDOC:
query_rings
Format: o=query_rings()
See also: query_armour, query_others.
This function returns an array with all rings in it.
*/
mixed query_rings() { 
  return rings; 
}

/* USERDOC:
heal_self
Format: heal_self(i)
Example: heal_self(10)
This function heals this living of i hitpoints and i spellpoints if possible.
*/
void heal_self(int h) {
  if (h <= 0)
    return;
  if (!is_npc && h>50 && previous_object()) 
    log_file("HEALS", ctime(time()) + ": " + name + ": " + h +
                      " by " + file_name(previous_object()) + "\n");
  if (!is_npc && this_player()!=this_object()
          && funcall(call,this_player(),"query_immortal")
          && !this_player()->query_archwiz())
    log_file("WIZHEALS",ctime(time()) + ": " + name + ": " + h +
             " by " + funcall(call,this_player(),"query_real_name") + "\n" +
             query_ip_name(this_player())+" "+
             query_ip_number(this_player())+"\n");

  hit_point += h;
  if (hit_point > max_hp)
    hit_point = max_hp;
  spell_points += h;
  if (spell_points > Max_sp)
    spell_points = Max_sp;
}

/* USERDOC:
restore_spell_points
Format: restore_spell_points(i)
Example: restore_spell_points(10)
See also: heal_self.
This function restores i spellpoints of the living, if possible.
*/
void restore_spell_points(int h) {
  spell_points += h;
  if (spell_points > Max_sp)
    spell_points = Max_sp;
}

/* USERDOC:
allowed_attack
Format: i=allowed_attack(o)
This function returns 0 if o may not attack this living, otherwise 1 is
returned.
*/
int allowed_attack(object ob) {
  return 1;
}

/* USERDOC:
attack_object
Format: attack_object(o)
Example: attack_object(this_player())
See also: allowed_attack.
This function lets this living attack o.
*/
int attack_object(object ob) {
  if (funcall(call,ob,"query_ghost") && !funcall(call,ob,"query_npc"))
    return( 0 );
  if (!allowed_attack(ob)) {
    write("You must not attack your fellow players !\n");
    return( 0 );
  }

  if (attacker_ob == ob) 
    return( 0 );

  attacker_ob = ob;
  attacker_ob->attacked_by(this_object());

  return( 1 );
}

/* USERDOC:
query_ghost
Format: i=query_ghost()
This function returns 0 if this living isn't a ghost.
*/
int query_ghost() { 
  return ghost; 
}

/* USERDOC:
test_if_any_here
Format: i=test_if_any_here()
This function returns 0 if there are no livings around this living that need
to be attacked. It always returns 1 for players.
*/
int test_if_any_here() {
  object room, ob;

  room = environment();
  if (!room) return 0;
  ob = first_inventory(room);
  while(ob) {
    if (interactive(ob) && ob!=this_object()) return 1;
    ob = next_inventory(ob);
  };
  return 0;
}

/* USERDOC:
show_age
Format: show_age()
See also: show_stats.
This function shows the age of this living.
*/
void show_age() {
  int i;

  write("Age:\t");
  i = age;
  if (i/43200) {
    write(i/43200 + " days ");
    i = i - (i/43200)*43200;
  }
  if (i/1800) {
    write(i/1800 + " hours ");
    i = i  - (i/1800)*1800;
  }
  if (i/30) {
    write(i/30 + " minutes ");
    i = i - (i/30)*30;
  }
  write(i + " seconds.\n");
}


/* USERDOC:
add_money
Format: add_money(i)
Example: add_money(10)
This is used by the shop etc. to add money to the living
*/
mixed add_money(int m) {
  object ob,ev;
  int l;

  l = money + m - (level) * 2500;

  if (ghost && m>0) {        
    object mo;
    write("You are not interested in the material world.\n");
    if (m==1) 
      say("One coin falls");
    else 
      say(m+" coins fall");
    say(" on the floor.\n");
    mo=clone_object("obj/money");
    funcall(call,mo,"set_money",m);
    move_object(mo,environment(this_object()));
    return 1;
  }
  if (l>0 && !is_wizard) {
    string ezmz;
    tell_object(TO, "You cannot carry any more coins.\n" +
                    "You drop the excess.\n");
    if (ev=environment(this_object())) {
      ob=clone_object("obj/money");
      funcall(call,ob,"set_money",l);
      move_object(ob,ev);
      (l==1?(ezmz=" coin"):(ezmz=" coins"));
      ezmz=" drops "+l+ezmz+".\n";
      say(TName+ezmz,0,this_player(),IName+ezmz);
    }
    m-=l;
  }
  money = money + m;
}

/* USERDOC:
query_spend_points
Format: i=query_spend_points()
This function should always return 0. It should be tested in guilds, if this
function returns anything other than 0, then points should be spend on stats
till it returns 0.
*/
int query_spend_points() {           
  return spend_points;
}

/* USERDOC:
query_money
Format: i=query_money()
See also: add_money.
This function returns the amount of money of this living.
*/
int query_money() {
  return money;
}

/* USERDOC:
query_exp
Format: i=query_exp()
See also: query_level.
This function returns the amount of experience of this living.
*/
int query_exp() {
  return experience;
}

/* USERDOC:
query_frog
Format: i=query_frog()
See also: frog_curse.
This function returns 0 if this living isn't a frog.
*/
int query_frog() { 
  return frog; 
}

/* USERDOC:
frog_curse
Format: i=frog_curse(i)
See also: query_frog.
If this living isn't a player, 0 is returned. Otherwise, if i is unequal to
0 then this living turns into a frog, and is told so. If i is equal to 0 then
this living turns normal again, and is told so.
*/
int frog_curse(int arg) {           
  if (is_npc) 
    return 0;
  if (arg) {
    if (frog) 
      return 1;
    tell_object(this_object(), "You turn into a frog !\n");
    frog = 1;
    return 1;
  }
  tell_object(this_object(), "You turn back to your former self !\n");
  frog = 0;
  return 0;
}

/* USERDOC:
run_away
Format: run_away()
This function makes this living run away from the current location. This is
used by wimpy/whimpy.
*/
void run_away() {
  object here, att;
  string *dirs;
  int i, j, z;

  if(whimpy==-1) 
    return;
  here = environment( this_object() );
  if(dirs=(string *)funcall(call,here,"query_room","dest_dir")) {
    z=sizeof(dirs)/2;
    i=0;
    j=random(z);
    while(i<z && here == environment()) {
      command(dirs[i*2+1]);
      i++; 
      j++;
      if(j>z) 
        j=0;
    }
  } 
  else { 
    i = 0;
    j = random(10);
    while(i<10 && here == environment()) {
      i += 1;
      j += 1;
      if (j > 10)
        j = 1;
      switch(j) {
        case 1:
          command("east");
          break;
        case 2:
          command("west");
          break;
        case 3:
          command("north");
          break;
        case 4:
          command("south");
          break;
        case 5:
          command("northeast");
          break;
        case 6:
          command("southeast");
          break;
        case 7:
          command("northwest");
          break;
        case 8:
          command("southwest");
          break;
        case 9:
          command("up");
          break;
        case 10:
          command("down");
          break;
      }
    }
  }

  if (here == environment()) {
    say(TName + " tried, but failed to run away.\n", this_object(),
        this_object(), IName + " tried, but failed to run away.\n");
    tell_object(this_object(), "Your legs tried to run away, but failed.\n");
    if ( this_player() != this_object() )
      tell_object( this_player(),TName+" tried, but failed to run away.\n" );
  } 
  else { 
    tell_room( here, TName+" runs away in sheer terror !!!\n" );
    tell_object(this_object(), "Your legs run away with you!\n");
  }
}

/* USERDOC:
query_wimpy
Format: i=query_wimpy()
See also: set_wimpy, run_away, query_hp.
This function returns the percentage of hitpoints below which the living will
run away.
*/
int query_wimpy() { 
  return whimpy; 
}

/* USERDOC:
set_wimpy
Format: set_wimpy(i)
Example: set_wimpy(20)
See also: query_wimpy, run_away, query_hp.
This function sets the percentage of hitpoints below which the living will run
away.
*/
void set_wimpy(int w) { 
  whimpy = w; 
}

/* USERDOC:
query_current_room
Format: s=query_current_room()
This function returns the filename of the room this living is in at the moment.
Not needed. instead of calling ob->query_current_room() u can just get do
file_name(environment(ob)) ergo DO NOT USE
*/
string query_current_room() { 
  return file_name(environment(this_object())); 
}

/* USERDOC:
stop_fight
Format: stop_fight()
This function makes this monster stop fighting it's current opponent, and
choose another person that was attacking him/her.
*/
int stop_fight() {
  attacker_ob = 0;
  if ( query_concentrating() ) abort_concentration();
  return 1;
}

/* USERDOC:
query_wc
Format: i=query_wc()
See also: query_n_wc.
This returns the same value as query_n_wc, the natural weaponclass of this
living. I think this is not the expected behaviour.
Changed so it returns wc of query_wielded() if there is one, else natural_wc
moonchild 110893
*/

int query_wc() {
  object o;
  if(o=(object)query_wielded())
    return (int)funcall(call,o,"weapon_class");
  return natural_wc; 
}

/* USERDOC:
query_n_wc
Format: i=query_n_wc()
See also: query_wc.
This returns the natural weapon class of this living.
DO NOT USE
*/
int query_n_wc() { 
  return natural_wc; 
}

/* USERDOC:
query_wielded_weapon
Format: o=query_wielded_weapon( whichHand )
See also: query_wielded.
This returns the same value as the query_wielded() function.
*/
object query_wielded_weapon( int whichHand ) { 
  if ( whichHand < 0 || whichHand >= number_of_arms )
    return( 0 );

  return( hands[whichHand] );
}

/* USERDOC:
query_ac
Format: i=query_ac()
This function returns the total armour class of this living.
*/
int query_ac() { 
  return armour_class; 
}

/* USERDOC:
reduce_hit_point
Format: reduce_hit_point(i)
Example: reduce_hit_point(10)
See also: heal_self, hit_player.
This function subtracts i from the amount of hitpoints of this living, but
won't let the living die, i.e. the hitpoints will remain above 0.
*/
int reduce_hit_point(int dam) {
  object o;

  if(TP!=TO) {
    log_file("REDUCE_HP",query_name()+" by ");
    if(!this_player()) 
      log_file("REDUCE_HP","?\n");
    else {
      log_file("REDUCE_HP",(string)funcall(call,this_player(),"query_name"));
      o=previous_object();
      if (o)
        log_file("REDUCE_HP", " " + file_name(o) + ", " +
                 (string)funcall(call,o,"short") + " (" + creator(o) + ")\n");
      else
        log_file("REDUCE_HP", " ??\n");
    }
  }
  hit_point -= dam;
  if (hit_point <= 0)
    hit_point = 1;
  return hit_point;
}

/* END EDIT */
/* USERDOC:
query_age
Format: i=query_age()
This returns the number of seconds this living is old.
*/
int query_age() { return age; }

/* USERDOC:
set_flag
Format: set_flag(i)
Example: set_flag(5)
See also: test_flag, clear_flag.
Flags manipulations. You are not supposed to do this arbitrarily. Every wizard
can allocate a few bits from the administrator, which he/she then may use. If 
you mainpulate bits that you don't know what they are used for, unexpected 
things can happen. Deze functie zet een van deze flags.
*/
void set_flag(int n) {
  if (!flags) flags = "";
#ifdef LOG_FLAGS
  log_file("FLAGS", name + " bit " + n + " set\n");
  if (previous_object()) {
    if (this_player()
             && this_player() != this_object()
             && interactive(this_player()))
      log_file("FLAGS", "Done by " +
               (string)funcall(call,this_player(),"query_real_name") +
               " using " + file_name(previous_object()) + ".\n");
  }
#endif
  flags = set_bit(flags, n);
}

/* USERDOC:
test_flag
Format: i1=test_flag(i2)
See also: set_flag, clear_flag.
This tests if flag i2 is set. i1 is 0 if it isn't.
*/
int test_flag(int n) {
  if (!flags) flags = "";
  return test_bit(flags, n);
}

/* USERDOC:
clear_flag
Format: clear_flag(i)
See also: set_flag, test_flag.
This function clears flag i.
*/
int clear_flag(int n) {
  if (!flags) flags = "";
#ifdef LOG_FLAGS
  log_file("FLAGS", name + " bit " + n + " cleared\n");
  if (previous_object()) {
    if (this_player()
          && this_player() != this_object()
          && interactive(this_player()))
      log_file("FLAGS", "Done by " +
               (string)funcall(call,this_player(),"query_real_name") +
               " using " + file_name(previous_object()) + ".\n");
  }
#endif
  flags = clear_bit(flags, n);
  return 1;
}

/* USERDOC:
set_race
Format: set_race(s)
Example: set_race("orc")
See also: query_race.
This sets the race of the living.
*/
int set_race(string arg) {
    if(!stringp(arg)) return 0;
    real_race=arg;
    return 1;
}

/* USERDOC:
set_size
Format: set_size(i)
Example: set_size(1)
See also: query_size.
This sets the size of the living, which is a number between 1 and
NUMBER_OF_SIZES.
*/
int set_size(int i) {
  real_size=i;
  if(real_size<1) real_size=1;
  if(real_size>NUMBER_OF_SIZES) real_size=NUMBER_OF_SIZES;
  sscanf(explode(WEIGHT_SIZE,"/")[real_size],"%d",weight);
  return 1;
}

/* USERDOC:
query_size
Format: i=query_size()
See also: set_size.
This returns the size of this living.
*/
int query_size() { 
  return frog ? 1 : real_size; 
}

/* USERDOC:
query_race
Format: s=query_race()
See also: set_race.
This returns the race of this living.
*/
string query_race() { 
  return frog ? "frog" : real_race; 
}

/* USERDOC:
query_arm_types
Format: m=query_arm_types([s])
This function returns all 'arm types' if no s is supplied, and otherwise it
will return the number of 'arm type' s. If s couldn't be found as 'arm type' 0
will be returned.
*/
mixed query_arm_types(int arg) {
  int i;
  if(!arg) return arm_types;
  i=member_array(arg, arm_types);
  if(i==-1) return 0;
  else return i;
}

int query_max_hp()          { return max_hp; }
int query_max_sp()          { return max_sp; }
int query_maxhp()           { return max_hp; }
int query_maxsp()           { return max_sp; }
int query_hp()              { return hit_point; }
int query_sp()              { return spell_points; }
int query_hit_point()       { return hit_point; }
int query_spell_points()    { return spell_points; }        


/* USERDOC:
query_r_stats
Format: i1=query_stats(i2)
See also: query_str, query_dex, query_con, query_int, query_chr, query_wis,
          set_stats.
This function returns the value of stat number i2. 0 is strength, 1 is
dexterity, 2 is constitution, 3 is intelligence, 4 is charisma and 5 is wisdom.
*/
nomask int query_r_stats(int i) { 
  return stats[i]; 
}

int query_stats(int i) { 
//    return funcall(call,this_object(),"query_r_stats",i); // why funcall ??

  int res;

  res = stats[i]+stat_modifiers[i];
  return( res < 1 ? 1 : res );
}

nomask int modify_stat( int i, int v ) {

  if ( i < 0 || i > 5 ) return( -1 );
  stat_modifiers[i] += v;
  stat_changed(i);
  return( query_stats(i) );
}

/* USERDOC:
query_str
Format: i=query_str()
See also: query_stats.
This function returns the value of strength of this living.
*/
int query_str() { 
  return Str; 
}

/* USERDOC:
query_dex
Format: i=query_dex()
See also: query_stats.
This function returns the dexterity of this living.
*/
int query_dex() { 
  return Dex; 
}

/* USERDOC:
query_con
Format: i=query_con()
See also: query_stats.
This function returns the constitution of this living.
*/
int query_con() { 
  return Con; 
}

/* USERDOC:
query_int
Format: i=query_int()
See also: query_stats.
This function returns the intelligence of this living.
*/
int query_int() { 
  return Int;
}

/* USERDOC:
query_wis
Format: i=query_wis()
See also: query_stats.
This function returns the wisdom of this living.
*/
int query_wis() {
  return Wis;
}

/* USERDOC:
query_chr
Format: i=query_chr()
See also: query_stats.
This function returns the charisma of this living.
*/
int query_chr() { 
  return Chr;
}

/* Note that previous object is 0 if called from ourselves. */

/* USERDOC:
set_stats
Format: set_stats(i1,i2)
Example: set_stats(1,5)
See also: query_stats.
This function sets stat i1 to value i2, and updates maximum hitpoints and
maximum spellpoints according to the guild of this living.
*/
void set_stats(int stat,int i) { /* guild+1 changed to guild */
  if ( i > 40 && interactive(this_object()) ) i = 40;
  stats[stat] = i;
  stat_changed( stat );
}

// --------------------------------------------------------------------------
// call this, whenever a stat changes !
// --------------------------------------------------------------------------
private void stat_changed( int stat ) {

  int ll;

  ll = funcall(call,this_object(),"query_legend_level");

  switch(stat) {
    case nr_con:
      max_hp=(int)funcall(call,GM,"query_maxhp",guild,query_stats(nr_con),ll);
      break;
    case nr_int:
      max_sp=(int)funcall(call,GM,"query_maxsp",guild,query_stats(nr_int),ll);
      break;
  }
}

/* This should be changed later into a race-depending stat handling*/
/* USERDOC:
set_str
Format: set_str(i)
Example: set_str(6)
See also: set_stats.
This sets the strength of this living.
*/
void set_str(int i) {
  set_stats(0, i);
}

/* USERDOC:
set_dex
Format: set_dex(i)
Example: set_dex(6)
See also: set_stats.
This sets the dexterity of this living.
*/
void set_dex(int i) {
  set_stats(1, i);
}

/* USERDOC:
set_con
Format: set_con(i)
Example: set_con(6)
See also: set_stats.
This sets the constitution of this living. It also updates the hitpoints.
*/
void set_con(int i) {
  set_stats(2, i);
}

/* USERDOC:
set_int
Format: set_int(i)
Example: set_int(6)
See also: set_stats.
This sets the intelligence of this living. It also updates the spellpoints.
*/
void set_int(int i) {
  set_stats(3, i);
}

/* USERDOC:
set_wis
Format: set_wis(i)
Example: set_wis(6)
See also: set_stats.
This sets the wisdom of this living.
*/
void set_wis(int i) {
  set_stats(4, i);
}

/* USERDOC:
set_chr
Format: set_chr(i)
Example: set_chr(6)
See also: set_stats.
This sets the charisma of this living.
*/
void set_chr(int i) {
  set_stats(5, i);
}


/* USERDOC:
query_npc
Format: i=query_npc()
This function returns 0 if this living is player.
*/
nomask int query_npc() {
  return is_npc;
}

/*----------- Most of the gender handling here: ------------*/

/* USERDOC:
query_gender
Format: i=query_gender()
See also: query_neuter, query_male, query_female, set_gender, 
          query_gender_string.
This function returns 0 if the living is neutral, 1 if he is male, and 2 if she
is female.
*/
int query_gender() { 
  if((name == "soozie") || (name == "herp")) return 0;
  if(query_ip_number(this_object()) && gender==0) gender=1;
  return gender;
}

/* USERDOC:
query_neuter
Format: i=query_neuter()
see also: query_gender, query_male, query_female, set_neuter.
This function returns 0 if this living isn't neutral.
OBSOLETE. Use query_gender.
*/
int query_neuter() { 
  return !gender; 
}

/* USERDOC:
query_male
Format: i=query_male()
See also: query_gender, query_neuter, query_female, set_male.
This function returns 0 if this living isn't male.
OBSOLETE. Use query_gender.
*/
int query_male() { return gender == 1; }

/* USERDOC:
query_female
Format: i=query_female()
See also: query_gender, query_neuter, query_male, set_female.
OBSOLETE. Use query_gender.
*/
int query_female() { return gender == 2; }

/* USERDOC:
set_gender
Format: set_gender(i)
Example: set_gender(2)
See also: set_male, set_female, query_gender.
This function sets the gender of the living to i.
    write("No more neuter. You are now male.\n");
    gender = 1;
    female == 2
*/
void set_gender(int g) {
  switch(g) {
    case 0:     if(query_ip_number(this_object())) gender = 1;
                else gender = 0; break;
    case 1..2:  gender=g; break;
  }
}

/* USERDOC:
set_neuter
Format: set_neuter()
See also: set_male, set_female, set_gender, query_neuter.
This function makes the living neuter. OBSOLETE. DO NOT USE. Use set_gender.
*/
void set_neuter() { gender = 0; }


/* USERDOC:
set_male
Format: set_male()
See also: set_neuter, set_female, set_gender, query_neuter.
This function makes the living male. OBSOLETE. DO NOT USE. Use set_gender.
*/
void set_male() { gender = 1; }

/* USERDOC:
set_female
Format: set_female()
See also: set_neuter, set_male, set_gender, query_neuter.
This function makes the living female. OBSOLETE. DO NOT USE. Use set_gender
*/
void set_female() { gender = 2; }

/* USERDOC:
query_gender_string
Format: s=query_gender_string()
See also: query_gender, set_gender, query_pronoun, query_possessive,
          query_objective.
This function returns 'neuter', 'male', or 'female' depending on the gender of
the living.
*/
string query_gender_string() {
  switch(gender) {
    case 0:  return "neuter"; break;
    case 1:  return "male";   break;
    default: return "female"; break;
  }
}

/* USERDOC:
query_pronoun
Format: s=query_pronoun()
See also: query_gender_string, query_possessive, query_objective.
This function returns 'it', 'he', 'she' depending on the gender of the living.
*/
string query_pronoun() {
  switch(gender) {
    case 0:  return "it";  break;
    case 1:  return "he";  break;
    default: return "she"; break;
  }
}

/* USERDOC:
query_possessive
Format: s=query_possessive()
See also: query_gender_string, query_pronoun, query_objective.
This function returns 'its', 'his', 'her' depending on the gender of the
living.
*/
string query_possessive() 
{
  switch(gender) {
    case 0:  return "its"; break;
    case 1:  return "his"; break;
    default: return "her"; break;
  }
}

/* USERDOC:
query_objective
Format: s=query_objective()
See also: query_gender_string, query_pronoun, query_possessive.
This function returns 'it', 'him' or 'her' depending on the gender of the
living.
*/
string query_objective() {
  switch(gender) {
    case 0:  return "it";  break;
    case 1:  return "him";  break;
    default: return "her"; break;
  }
}

dump() {
  write("weight = " + to_string(weight) + ", local_weight = " +
        to_string(local_weight) + "\n");
  write("hunter = ");write(hunter);write("\n");
  if ( is_npc ) printf("hunted = %O\n", this_object()->get_hunted() );
  else          write("hunted = players do not hunt\n");
  write("attacker_ob = ");write(attacker_ob);write("\n");
  write("alt_attacker_ob = ");write("removed\n");
}

// ------ language catch_tell
// -> msg: the message, src: the one, who (what ?) started the chain
// -> kind: 1=say, 2=tell, 3=shout
int lcatch_tell( string act, string msg, object who, int kind ) {

  int    sk_me, sk_who, enc_level, lang;
  string name;

  if ( !act || !msg || !who ) return( 0 );

  lang      = funcall(call,who,"speaks_in");
  sk_who    = funcall(call,who,"language_skill",lang);
  sk_me     = language_skill( lang );
  enc_level = sk_me > sk_who ? sk_who : sk_me;
  msg       = encrypt_msg( msg, enc_level );
  if ( who->is_invis_for(this_object()) )
    name = IName;
  else
    name = capitalize( funcall(call,who,"query_real_name") );
  tell_object( this_object(), name+" "+act+" "+msg );
  return( 1 );
}

static string encrypt_msg( string msg, int lvl ) {

  int len, doCrypt, i, j, maxj;

  lvl = (lvl/10);
  len = strlen( msg );

  if ( lvl > 8 ) return( msg );       // speak good enough to understand all

  if ( lvl < 2 ) {
    for ( i = 0; i < len; i++ ) {
      if ( msg[i] >= 'A' && msg[i] <= 'Z' ) msg[i] = 'A'+25-msg[i]+'A'; 
      else if ( msg[i] >= 'a' && msg[i] <= 'z' ) msg[i] = 'a'+25-msg[i]+'a'; 
      else if ( msg[i] >= '0' && msg[i] <= '9' ) msg[i] = '0'+9-msg[i]+'0'; 
    }
    return( msg );
  }

  doCrypt = 0;

  lvl += 2;
  doCrypt = random(lvl);
  for ( i = 0; i < len; i+=lvl ) {
    maxj = i+lvl > len ? len : i+lvl;
    for ( j = i; j < maxj; j++ ) {
      if ( j != doCrypt ) ;
      else if ( msg[j] >= 'A' && msg[j] <= 'Z' ) msg[j] = 'A'+25-msg[j]+'A'; 
      else if ( msg[j] >= 'a' && msg[j] <= 'z' ) msg[j] = 'a'+25-msg[j]+'a'; 
      else if ( msg[j] >= '0' && msg[j] <= '9' ) msg[j] = '0'+9-msg[j]+'0'; 
    }
    doCrypt += lvl;
  }

  return( msg );
}

// ----- languages --------------------
// ----- take care when changing the following function, you could increase
// ----- memory-usage DRAMATIALLY (pat)

int set_speaks_in( int lang ) {
  if ( !languages || sizeof(languages) <= lang )     // not so much allocated
    return( _speaks_in = 0 );                       // let it speak in common
  return( _speaks_in = lang );
}

int speaks_in( ) {
  return( _speaks_in );
}

int act_language_skill( ) {
  return( language_skill( _speaks_in ) );
}

int language_skill( int lang ) {
  if ( (!languages || !sizeof(languages)) && lang == 0 )   // alw. common !
    return( 100 );
  else if ( !languages || lang < 0 || lang >= sizeof(languages) )
    return( 0 );
  return( languages[lang] );
}

void set_language_skill( int lang, int skill ) {
  int i, len;

  if ( lang < 0 || lang >= NO_OF_LANG || skill < 0 || skill > 100 )
    return;
  if ( !languages ) { 
    len = lang+1;
    languages = allocate( len );
    for ( i = 0; i < len; i++ ) languages[i] = 0;
  }
  else if ( lang >= sizeof(languages) ) {
    int *tmp_arr;
    len = (lang+1) - sizeof(languages);
    tmp_arr = allocate(len);
    for ( i = 0; i < len; i++ ) tmp_arr[i] = 0;
    languages += tmp_arr;
  }
  languages[lang] = skill;
}

string language_name( int lang ) {

  switch( lang ) {
    case 0:  return( "common" );
    case 1:  return( "nihonese" );
    case 2:  return( "magika" );
    default: return( "" );
  }

  return( "" );
}

string language_skill_name( int skill ) {
   switch( skill ) {
      case  0..10: return( "not learned" );
      case 11..20: return( "a bit" );
      case 21..30: return( "very poor" );
      case 31..40: return( "poor" );
      case 41..50: return( "very broken" );
      case 51..60: return( "broken" );
      case 61..70: return( "good" );
      case 71..80: return( "nearly fluent" );
      default:     return( "fluent" );
   }
}

/******************   P R O C E S S _ S P E L L  ***************************/
/*
 * most of the spell_handling is here
 *
 * arg: arg        -- the whole input from the add_action("cast")
 *                   z.B: arg == "'chainlightning' [name]"
 * return: always 1 
 *
 * NOTE: this functions is TOTALY overridden by the monster !
 */
int nprocess_spell(string arg) {

  int idx;
  mixed *si;
  string fn,                   // the file with the spell_code
  which,                 // the command to trigger the spell
  sarg,                 // the 2nd argument -> target of the spell
  tpn;

  if ( !spells ) {
    write( "You do not know any spells!\n" );
    return( 1 );
  }
  if ( !arg ) {
    write( "Cast which spell ?\n" );
    return( 1 );
  }
  if ( next_spell ) {
    write("Have patience, you are already concentrating ...\n" );
    return( 1 );
  }
  if ( arg[0]!='\'') {
    write("Magic must always be enclosed by the magic symbols : '\n");
    return( 1 );
  }
  if ( sscanf( arg, "'%s' %s", which, sarg ) != 2 ) {
    if ( sscanf( arg, "'%s'", which ) != 1 ) {
      write( "Uh ? Say it again.\n" );
      return( 1 );
    }
  }

  if ( (idx = match_array( spells[0], which )) < 0 ) {
    write( "You do not know such a spell.\n" );
    return( 1 ); 
  }

  if ( !(fn = SPELL_MASTER->get_spell(spells[0][idx])) ) {
    write( "This spell has been (temporarily ?) removed !\n" );
    return( 1 );
  }
  if ( !funcall(call,this_object(),"query_immortal") 
          && !(funcall(call,fn,"may_cast",guild,
                    level+funcall(call,this_object(),"query_legend_level"))) ) {
    write( "This spell is beyond your casting-abilities.\n" );
    return( 1 );
  }

  next_spell = fn;
  next_spell_arg = sarg;
  next_spell_time = spells[3][idx];
  next_spell_data = ({spells[1][idx]}) + ({spells[2][idx]});

  switch( funcall( call, TP, "query_guild" ) ) {
    case 8:  funcall( call, next_spell, "display_utter", 1 ); break;
    case 5:  funcall( call, next_spell, "display_utter", 2 ); break;
    default: funcall( call, next_spell, "display_utter", 2 ); break;
  }

  if ( spells[3][idx] < 0 )            // immediate
    nrelease_spell( ); 
  else if(interactive(TO)) {           // casting time
    TO->check_input(next_spell, "abort_spell");
  }

  return( 1 );
}

/******************   P R O C E S S _ A B I L I T Y  ***********************
 *
 * NOTE: this functions is TOTALY overridden by the monster !
 */
int process_ability(string arg) {

  int idx;
  mixed *si;
  string fn,                   // the file with the spell_code
         which;       // the ability

  if ( !abilities ) {
    write( "You do not have any special abilities !\n" );
    return( 1 );
  }
  if ( next_spell ) {
    write("Have patience, you are already concentrating ...\n" );
    return( 1 );
  }

  which = query_verb();

  if ( (idx = member_array( which, abilities[0] )) < 0 ) {
    write( "You do not know of such an ability.\n" );
    return( 1 ); 
  }

  if ( !(fn = ABILITY_MASTER->get_ability(abilities[0][idx])) ) {
    write( "This ability has been (temporarily ?) removed !\n" );
    return( 1 );
  }
  if ( !funcall(call,this_object(),"query_immortal") 
           && !(funcall(call,fn,"may_use",guild,
                   level+funcall(call,this_object(),"query_legend_level"))) ) {
    write( "This ability is beyond your knowledge.\n" );
    return( 1 );
  }

  next_spell = fn;
  next_spell_arg = arg;
  next_spell_time = abilities[3][idx];
  next_spell_data = ({abilities[1][idx]}) + ({abilities[2][idx]});

  funcall( call, next_spell, "display_prepare" );

  if ( abilities[3][idx] < 0 )         // immediate
    nrelease_spell( ); 

  return( 1 );
}


/******************   R E L E A S E _ S P E L L   ************************/
/*
 * Is actually doing the spell or the ability
 * 
 * arg: none
 * return: undefined
 */
static void nrelease_spell( ) {

  funcall(call,next_spell,"release",
                 next_spell_arg, next_spell_data[0], next_spell_data[1] ); 

  if ( interactive(this_object()) )
    this_object()->uncheck_input();

  next_spell_time = -1;
  next_spell = 0;
  next_spell_arg = 0;
  next_spell_data = 0;
}


/**************************  H A N D L E _ S P E L L ******************/
/*
 * Counts the spell_time down to zero and releases the
 * spell then with <release_spell>
 *
 * return: always 1
 * arg: none
 */
int nhandle_spell() {
  if ( next_spell_time == 0 )
    nrelease_spell( );
  else if ( next_spell_time > 0 )
    next_spell_time--;

  if ( interactive(this_object()) )          // brauch ma des no ?? (pat)
    enable_interactive(this_object());

  return( 1 );
}

int query_concentrating() {
  if ( next_spell_time > -1 ) return( 1 );
  return( 0 );
}

int prac_help( string arg ) {
  string res;

  if ( arg == "spell" || arg == "spells" ) {
    res = sprintf( "%-20s %-7s %-7s  |  %-20s %-7s %-7s\n\n",
                   "Spell", "Mastery", "Time", "Spell", "Mastery", "Time" );
    res += SPELL_MASTER->show_spells( this_object() );
    this_player()->more_string( res );
  }
  else if ( arg == "ability" || arg == "abilities" ) {
    res = sprintf( "%-20s %-7s %-7s  |  %-20s %-7s %-7s\n\n",
                   "Ability", "Mastery", "Time", "Ability", "Mastery", "Time" );
    res += ABILITY_MASTER->show_abilities( this_object() ); 
    this_player()->more_string( res );
  }
  else if ( arg == "skill" || arg == "skills" ) {
    res = sprintf( "%-20s %-7s          |  %-20s %-7s\n\n",
                   "Skill", "Mastery", "Skill", "Mastery" );
    res += SKILL_MASTER->show_skills( this_object() ); 
    this_player()->more_string( res );
  }
  else {
    res = sprintf( "%-20s %-7s %-7s  |  %-20s %-7s %-7s\n\n",
                   "Spell/Ability", "Mastery", "Time", "Spell/Ability",
                   "Mastery", "Time" );
    res += SPELL_MASTER->show_spells( this_object() );
    res += ABILITY_MASTER->show_abilities( this_object() );
    res += SKILL_MASTER->show_skills( this_object() ); 
    this_player()->more_string( res );
  }

  return( 1 );
}

int query_holded() {
  if (hold_flag)
  return 1;

  return 0;
}

grmems_in_room() { return ({ }); }

void set_infravision()    { infravis = 1; }
int  infravision()        { return( infravis ); }

int query_living() { return 1; } /* Steerpike, 010696 */
