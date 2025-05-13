inherit "/obj/monster";

#define SPELL_MASTER    "/spells/master"
#define ABILITY_MASTER  "/abilities/master"
#define SKILL_MASTER    "/masters/skills"
#define TP              this_player()

private string *spells;
private string *abilities;
private string *skills;

// ----- prototypes
int learn_spell( object who, string spell_name, string file_name, int max_sk );
int advance_spell( object who, string spell_name, string file_name, int max_sk);
int learn_ability( object who, string ab_name, string file_name, int max_sk );
int advance_ability( object who, string ab_name, string file_name, int max_sk );
int learn_skill( object who, string ab_name, int max_sk );
int advance_skill( object who, string ab_name, int max_sk );
void list_prac( object who );

// ----- do NOT override these !
static int increase_skill95( object who, int actSkill, int maxSkill );
static int increase_skill100( object who, int actSkill, int maxSkill );
static void recalc_spell_speed(object who,string spell_name,string file_name);
static void recalc_ability_speed(object who, string ab_name, string file_name);

static void set_spells( string *sp );
static void set_abilities( string *ab );
static void set_skills( string *sk );
static string *get_spells( );
static string *get_abilities( );
static string *get_skills( );

void reset( int tick )
{
   ::reset(tick);

   if ( tick ) return;

   set_name( "practice monster" );
   set_short( "practice monster" );
   set_long( "This is the practice monster. You can practice at it !\n" );
   set_level( 1 );

   spells = ({});
   abilities = ({});
   skills = ({});
}

void init( )
{
   ::init();

   add_action( "do_prac", "prac", 5 );
}

// ----- initializing -------------------------------------------------------
static void set_spells( string *sp )
{
   if ( sp && sizeof(sp) )
      spells = sp;
}
static void set_abilities( string *ab )
{
   if ( ab && sizeof(ab) )
      abilities = ab;
}
static void set_skills( string *sk )
{
   if ( sk && sizeof(sk) )
      skills = sk;
}

static string *get_spells()           { return( spells ); }
static string *get_abilities()        { return( abilities ); }
static string *get_skills()           { return( skills ); }

// --------- add_action "practice" ------------------------------------------
int do_prac( string what )
{
   string fn;

   if ( !what ) {
      list_prac( TP );
      return( 1 );
   }

   // ----- one of the spells in the spell-master ? --------
   if ( (fn = SPELL_MASTER->get_spell(what)) ) {
      if ( TP->get_spell( what ) )
         return( advance_spell( TP, what, fn, 95 ) );
      else
         return( learn_spell( TP, what, fn, 95 ) );
   }
   // ----- one of the abilities in the ability-master ? ---
   else if ( (fn = ABILITY_MASTER->get_ability(what)) ) {
      if ( TP->get_ability( what ) )
         return( advance_ability( TP, what, fn, 95 ) );
      else
         return( learn_ability( TP, what, fn, 95 ) );
   }
   // ----- one of the skills in the skill-master ? ---------
   else if ( SKILL_MASTER->get_skill(what) ) {
      if ( TP->get_skill_value( what ) > -1 )
         return( advance_skill( TP, what, 100 ) );
      else
         return( learn_skill( TP, what, 100 ) );
   }
   else
      write( "You cannot practice "+what+" here.\n" );

   return( 1 );
}

// --------- advance an already know spell ----------------------------------
int advance_spell( object who, string spell_name, string file_name, int max_sk )
{
   int sk;

   if ( member_array( spell_name, spells ) < 0 ) return( -3 );

   sk = increase_skill95( who, who->get_spell_skill(spell_name),
                               who->get_spell_maxskill(spell_name) );
   if ( sk < 0 ) return( sk );
   if ( who->decrease_practice_sessions() < 0 ) return ( -2 );
   who->set_spell_skill( spell_name, sk );
   recalc_spell_speed( who, spell_name, file_name );

   return( sk );
}

// --------- learn a new spell ----------------------------------------------
int learn_spell( object who, string spell_name, string file_name, int max_sk )
{
   int sp, sk, lvl;

   lvl = file_name->level(who->query_guild());
   if ( lvl == -1 || lvl > who->query_level() + who->query_legend_level() )
      return( -4 );
   if ( member_array( spell_name, spells ) < 0 ) return( -3 );

   if ( who->practice_sessions() <= 0 ) return( -2 );
   sp = apply( call, file_name, "speed", who->query_level(), who );
   if ( who->change_spell( spell_name, 1, max_sk, sp ) == -1 )
      return( -1 );

   max_sk = max_sk > apply(call,who,"get_spell_maxskill",spell_name) ?
                 apply(call,who,"get_spell_maxskill",spell_name) : max_sk;
   sk = increase_skill95( who, who->get_spell_skill(spell_name), max_sk );
   if ( sk < 0 ) return( sk );
   if ( who->decrease_practice_sessions() < 0 ) return ( -2 );
   who->set_spell_skill( spell_name, sk );
   recalc_spell_speed( who, spell_name, file_name );

   return( sk );
}

// --------- advance an already known ability -------------------------------
int advance_ability( object who, string ab_name, string file_name, int max_sk )
{
   int sk;

   if ( member_array( ab_name, abilities ) < 0 ) return( -3 );

   sk = increase_skill95( who, who->get_ability_skill(ab_name),
                               who->get_ability_maxskill(ab_name) );
   if ( sk < 0 ) return( sk );
   if ( who->decrease_practice_sessions() < 0 ) return ( -2 );
   who->set_ability_skill( ab_name, sk );
   recalc_ability_speed( who, ab_name, file_name );

   return( sk );
}

// --------- learn a new ability --------------------------------------------
int learn_ability( object who, string ab_name, string file_name, int max_sk )
{
   int sp, sk, lvl;

   lvl = file_name->level(who->query_guild());
   if ( lvl == -1 || lvl > who->query_level() + who->query_legend_level() )
      return( -4 );
   if ( member_array( ab_name, abilities ) < 0 ) return( -3 );

   if ( who->practice_sessions() <= 0 ) return( -2 );
   sp = apply( call, file_name, "speed", who->query_level(), who );
   if ( who->change_ability( ab_name, 1, max_sk, sp ) == -1 )
      return( -1 );

   max_sk = max_sk > apply(call,who,"get_ability_maxskill",ab_name) ?
                 apply(call,who,"get_ability_maxskill",ab_name) : max_sk;
   sk = increase_skill95( who, who->get_ability_skill(ab_name), max_sk );
   if ( sk < 0 ) return( sk );
   if ( who->decrease_practice_sessions() < 0 ) return ( -2 );
   who->set_ability_skill( ab_name, sk );
   recalc_ability_speed( who, ab_name, file_name );

   return( sk );
}

// --------- advance an already known skill ----------------------------------
int advance_skill( object who, string sk_name, int max_sk )
{
   int sk;

   if ( member_array( sk_name, skills ) < 0 ) return( -3 );
   sk = increase_skill100( who, who->get_skill_value(sk_name),
                               who->get_skill_max(sk_name) );
   if ( sk < 0 ) return( sk );
   if ( who->decrease_practice_sessions() < 0 ) return ( -2 );
   who->set_skill_value( sk_name, sk );

   return( sk );
}

// --------- learn a new skill ------------------------------------------------
int learn_skill( object who, string sk_name, int max_sk )
{
   int sk, lvl;

   lvl = SKILL_MASTER->level(sk_name, who->query_guild() );
   if ( lvl == -1 || lvl > who->query_level() + who->query_legend_level() )
      return( -4 );
   if ( member_array( sk_name, skills ) < 0 ) return( -3 );

   if ( who->practice_sessions() <= 0 ) return( -2 );
   if ( who->nchange_skill( sk_name, 1, max_sk ) == -1 )
      return( -1 );

   max_sk = max_sk > who->get_skill_max(sk_name) ?
                 who->get_skill_max(sk_name) : max_sk;
   sk = increase_skill100( who, who->get_skill_value(sk_name), max_sk );
   if ( sk < 0 ) return( sk );
   if ( who->decrease_practice_sessions() < 0 ) return ( -2 );
   who->set_skill_value( sk_name, sk );

   return( sk );
}

// ---------- increase skill -------------------------------------------------
static int increase_skill95( object who, int actSkill, int maxSkill )
{
   int tmp, fact, lvl, it, diff;

   // ----- base raise -----
   if ( actSkill < 25 ) tmp = 10+random(10);
   else if( actSkill < 40 ) tmp = 8+random(8);
   else if( actSkill < 50 ) tmp = 7+random(7);
   else if( actSkill < 60 ) tmp = 6+random(6);
   else if( actSkill < 70 ) tmp = 5+random(5);
   else if( actSkill < 80 ) tmp = 4+random(4);
   else if( actSkill < 90 ) tmp = 3+random(3);
   else if( actSkill < 95 ) tmp = 2+random(2);
   else return( -1 );

   // ----- consider int too ----- 
   if ( who ) { 
     lvl = apply( call, who, "query_level" );
     it = apply( call, who, "query_int" );

     if ( lvl > it ) diff = lvl - it;
     else if ( it > lvl ) diff = it - lvl;
     else diff = 0;

     fact = (diff+1)/2*5+100;
     tmp = tmp*fact/100;
   }

   // ----- increase it -----
   actSkill += tmp;

   if ( actSkill > maxSkill )
      actSkill = maxSkill;

   return( actSkill );
}

static int increase_skill100( object who, int actSkill, int maxSkill )
{
   int tmp, fact, lvl, it, diff;

   // ----- base raise -----
   if ( actSkill < 15 ) tmp = 10+random(10);
   else if( actSkill < 30 ) tmp = 8+random(8);
   else if( actSkill < 40 ) tmp = 7+random(7);
   else if( actSkill < 50 ) tmp = 6+random(6);
   else if( actSkill < 60 ) tmp = 5+random(5);
   else if( actSkill < 70 ) tmp = 4+random(4);
   else if( actSkill < 80 ) tmp = 3+random(3);
   else if( actSkill < 90 ) tmp = 2+random(2);
   else if( actSkill < 100) tmp = 1+random(1);
   else return( -1 );

   // ----- consider int too ----- 
   if ( who ) { 
     lvl = apply( call, who, "query_level" );
     it = apply( call, who, "query_int" );

     if ( lvl > it ) diff = lvl - it;
     else if ( it > lvl ) diff = it - lvl;
     else diff = 0;

     fact = (diff+1)/2*5+100;
     tmp = tmp*fact/100;
   }

   // ----- increase it -----
   actSkill += tmp;

   if ( actSkill > maxSkill )
      actSkill = maxSkill;

   return( actSkill );
}

// ----- recalculate the speed of the spell ---------------------------------
static void recalc_spell_speed(object who,string spell_name,string file_name)
{
   int sp;

   sp = apply( call, file_name, "speed", who->query_level(), who );
   who->set_spell_speed( spell_name, sp );
}

// ----- recalculate the speed of the ability -------------------------------
static void recalc_ability_speed(object who, string ab_name, string file_name)
{
   int sp;

   sp = apply( call, file_name, "speed", who->query_level(), who );
   who->set_ability_speed( ab_name, sp );
}

// ---------- THE LIST -------------------------------------------------------
void list_prac( object who )
{
   string res, fn;
   int    i, max, sk, lvl, gui;

   gui = who->query_guild();
   max = sizeof( spells );
   res = 
"----- SPELLS --------------------------------------------------------------\n";
   for ( i = 0; i < max; i++ ) {
      sk = who->get_spell_skill( spells[i] );
      if ( sk < 0 ) sk = 0;
      fn = SPELL_MASTER->get_spell( spells[i] );
      lvl = fn->level(gui);
      if ( lvl == -1 )
         res+=sprintf("[NA ] %-26s %3d%% ", spells[i],sk);
      else if ( lvl > 29 )
         res+=sprintf("[L%2d] %-26s %3d%% ", lvl-29, spells[i],sk);
      else
         res+=sprintf("[%3d] %-26s %3d%% ", lvl, spells[i],sk);
      if ( (i%2) ) res += "\n";
   }
   if ( (i%2) ) res += "\n";
   res += 
"----- ABILITIES -----------------------------------------------------------\n";
   max = sizeof( abilities );
   for ( i = 0; i < max; i++ ) {
      sk = who->get_ability_skill( abilities[i] );
      if ( sk < 0 ) sk = 0;
      fn = ABILITY_MASTER->get_ability( abilities[i] );
      lvl = fn->level(gui);
      if ( lvl == -1 )
         res+=sprintf("[NA ] %-26s %3d%% ", abilities[i],sk);
      else if ( lvl > 29 )
        res+=sprintf("[L%2d] %-26s %3d%% ", lvl-29, abilities[i],sk);
      else
        res+=sprintf("[%3d] %-26s %3d%% ", lvl, abilities[i],sk);
      if ( (i%2) ) res += "\n";
   }
   if ( (i%2) ) res += "\n";
   res += 
"----- SKILLS --------------------------------------------------------------\n";
   max = sizeof( skills );
   for ( i = 0; i < max; i++ ) {
      sk = who->get_skill_value( skills[i] );
      if ( sk == -1 ) sk = 0;
      lvl = SKILL_MASTER->level(skills[i], gui);
      if ( lvl == -1 )
         res+=sprintf("[NA ] %-26s %3d%% ", skills[i],sk);
      else if ( lvl > 29 )
        res+=sprintf("[L%2d] %-26s %3d%% ", lvl-29, skills[i],sk);
      else
        res+=sprintf("[%3d] %-26s %3d%% ", lvl, skills[i],sk);
      if ( (i%2) ) res += "\n";
   }
   if ( (i%2) ) res += "\n";
   res +=
"---------------------------------------------------------------------------\n";
   res += "You have "+who->practice_sessions()+" practice sessions left.\n";
   res += 
"---------------------------------------------------------------------------\n";

   who->more_string( res );
}
