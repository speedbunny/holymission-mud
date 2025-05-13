inherit "/guild/prac_monster";

#define PR_SPELLS ({ "cloak",\
                     "brainstorm",\
                     "terror",\
                     "fearall",\
                     "bolt",\
                     "noattack",\
                  })

#define PR_ABIL   ({ })

#define PR_SKILLS ({ "parry",\
                     "multi-wield",\
                  })

#define TP             this_player()
#define TO             this_object()
#define SPELL_MASTER   "/spells/master"
#define ABILITY_MASTER "/abilities/master"
#define SKILL_MASTER   "/masters/skills"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_race( "yag" );
   set_name( "Yoda" );
   set_alias( "yoda" );
   set_level(70);
//   set_guild( 10 );
   set_short( "Yoda, Jedi Master" );
   set_long(
        "A very wise and old humanoid. He has searched the universe\n" +
        "to find the truths and powers he holds. He is\n" +
        "willing to teach you spells and abilities.\n");
   set_gender( 1 );

   set_number_of_arms( 2 );

transfer(clone_object("/players/colossus/guild/soul"),TO);
   transfer(clone_object("/players/mangla/guild/lightsaber"),TO);
   transfer(clone_object("/players/mangla/guild/lightsaber"),TO);
   command( "wield handle" );
   command( "wield handle 2");

}

int query_show_short( )
{
   return( 1 );
}

// ------------ SPELLS ------------------------------------------------------
int advance_spell( object who, string sn, string fn, int max_sk )
{
   int res;

   if( who->query_guild() != 10) {
      ltell(who,"says:","I do not teach those that are not at one with the force.\n",TO);
      return( 1 );
   }

   if ( member_array( sn, PR_SPELLS ) < 0 ) {
      ltell( who, "says:", "I am not versed in such knowledge.\n",TO );
      return( 1 );
   }

   res = ::advance_spell( who, sn, fn, 95 );
   if ( res == -2 ) {
      ltell( who, "says:", "I have taught you all I can for now. You must seek more knowledge.\n",TO );
   }
   else if ( res < 0 )
      ltell( who, "says:", "You are strong in the force. I can teach you no more about that skill.\n", TO );
   else
      tell_object(who,"Yoda teaches you to improve your spell.\n");

   return( res );
}

int learn_spell( object who, string sn, string fn, int max_sk )
{
   int    res, idx;

   if( who->query_guild() != 10 ) {
      ltell( who, "says:","I do not teach those that are not one with the force.\n", TO );
      return( 1 );
   }

   idx = member_array( sn, PR_SPELLS );
   if ( idx < 0 ) {
      ltell( who, "says:","I am not versed in such knowledge.\n",TO);
      return( 1 );
   }
   if( fn->level(10) <= 0
        || fn->level(10) > (TP->query_level()+TP->query_legend_level()) )
   {
      ltell( who, "says:","You must seeks more experience before I can teach you more.\n",TO);
      return( 1 );
   }

   res = ::learn_spell( who, sn, fn, 95 );
   if ( res == -2 )
      ltell( who, "says:", "You have to go out and earn more experience.\n",TO);
   else if ( res < 0 )
      ltell(who,"says:","I am unable to teach you this spell.\n",TO);
   else
      tell_object(who,"Yoda shows you how to manipulate the force for the spell.\n");

   return( res );
}

// ------------ ABILITIES ---------------------------------------------------
/* None yet so not needed.
int advance_ability( object who, string sn, string fn, int max_sk )
{
   int res;

   if ( who->query_guild() != 10 ) {
      ltell( who, "says:", "You are not one with teh force.\n", this_object() );
      return( 1 );
   }

   if ( member_array( sn, PR_ABIL ) < 0 ) {
      ltell( who, "says:", "I do not know of such an ability.\n",
                   this_object() );
      return( 1 );
   }

   res = ::advance_ability( who, sn, fn, 95 );
   if ( res == -2 ) {
      ltell( who, "says:", "You have to go out and earn more experience.\n",TO);
   }
   else if ( res < 0 )
      ltell( who, "says:", "You have reached your mastery in that ability.\n",
                   this_object() );
   else
    tell_object(who,"Yoda teaches you some further techniques.\n");

   return( res );
}

int learn_ability( object who, string sn, string fn, int max_sk )
{
   int    res, idx;

   if ( who->query_guild() != 10 ) {
      ltell( who, "says:", "You are not at one with the force.\n", this_object() );
      return( 1 );
   }

   idx = member_array( sn, PR_ABIL );
   if ( idx < 0 ) {
      ltell( who, "says:", "I do not know of such an ability.\n",
                   this_object() );
      return( 1 );
   }
   if ( fn->level(10) <= 0 
        || fn->level(10) > (TP->query_level()+TP->query_legend_level()) )
   {
      ltell( who, "says:", "You must gain more experience first.\n",
                   this_object() );
      tell_object( who, "Yoda wishes you luck.\n" );
      return( 1 );
   }

   res = ::learn_ability( who, sn, fn, 95 );
   if ( res == -2 )
      ltell( who, "says:", "You must gain more experience.\n",TO);
   else if ( res < 0 )
     ltell(who,"says:","I cannot teach you this ability.\n",
                   this_object() );
   else
     tell_object(who,"Yoda teaches you the mysteries of the ability !\n");

   return( res );
}
*/

// SKILLS_START
// ------------ SKILLS ------------------------------------------------------
int advance_skill( object who, string sn, int max_sk )
{
   int res;

   if ( who->query_guild() != 10 ) {
      ltell( who, "says:", "You are not at one with the force.\n", this_object() );
      return( 1 );
   }

   if ( member_array( sn, PR_SKILLS ) < 0 ) {
      ltell( who, "says:", "I do not know of such a skill.\n",
                   this_object() );
      return( 1 );
   }

   res = ::advance_skill( who, sn, 100 );
   if ( res == -2 ) {
      ltell( who, "says:", "You earn more experience.\n",TO);
   }
   else if ( res < 0 )
      ltell( who, "says:", "You may not advance any further.\n",
                   this_object() );
   else
    tell_object(who,"Yoda shows you more mysteries of the skill.\n");

   return( res );
}

int learn_skill( object who, string sn, int max_sk )
{
   int    res, idx, lvl;

   if ( who->query_guild() != 10 ) {                           
      ltell( who, "says:", "Uoua re not at one with teh force.\n", this_object() );
      return( 1 );
   }

   idx = member_array( sn, PR_SKILLS );
   if ( idx < 0 ) {
      ltell( who, "says:", "I do not know of such a skill.\n",
                   this_object() );
      return( 1 );
   }
   lvl = SKILL_MASTER->level(PR_SKILLS[idx], 10);
   if ( lvl <= 0 || lvl > (TP->query_level()+TP->query_legend_level()) )
   {
      ltell( who, "says:", "You must gain more knowledge first.\n",
                   this_object() );
      tell_object( who, "Yoda wishes you good fortune.\n" );
      return( 1 );
   }

   res = ::learn_skill( who, sn, 100 );
   if ( res == -2 )
      ltell( who, "says:", "You have to go out and earn more experience.\n",TO);
   else if ( res < 0 )
     ltell(who,"says:","Somehow I cannot teach you this skill.\n",
                   this_object() );
   else
     tell_object(who,"Yoda teaches you some more tricks in the skill.\n");

   return( res );
}

// ---------- THE LIST -------------------------------------------------------
void list_prac( object who )
{
   string res, fn;
   int    i, max, sk, lvl;

   if ( who->query_guild() != 10 ) {
      write( "Yoda yodels !\n" );
      return;
   }

   max = sizeof( PR_SPELLS );
   res = "-------------------------------------\n";
   for ( i = 0; i < max; i++ ) {
write("DEBUG: "+PR_SPELLS[i]+"\n");
      sk = who->get_spell_skill( PR_SPELLS[i] );
      if ( sk == -1 ) sk = 0;
      fn = SPELL_MASTER->get_spell( PR_SPELLS[i] );
      lvl = fn->level(10);
      if ( lvl > 29 )
        res+=sprintf("[L%2d] %-26s %3d%%\n", lvl-29, PR_SPELLS[i],sk);
      else
        res+=sprintf("[%3d] %-26s %3d%%\n", lvl, PR_SPELLS[i],sk);
   }
   max = sizeof( PR_ABIL );
   for ( i = 0; i < max; i++ ) {
      sk = who->get_ability_skill( PR_ABIL[i] );
      if ( sk == -1 ) sk = 0;
      fn = ABILITY_MASTER->get_ability( PR_ABIL[i] );
      lvl = fn->level(10);
      if ( lvl > 29 )
        res+=sprintf("[L%2d] %-26s %3d%%\n", lvl-29, PR_ABIL[i],sk);
      else
        res+=sprintf("[%3d] %-26s %3d%%\n", lvl, PR_ABIL[i],sk);
   }
   max = sizeof( PR_SKILLS );
   for ( i = 0; i < max; i++ ) {
      sk = who->get_skill_value( PR_SKILLS[i] );
      if ( sk == -1 ) sk = 0;
      lvl = SKILL_MASTER->level(PR_SKILLS[i], 10);
      if ( lvl > 29 )
        res+=sprintf("[L%2d] %-26s %3d%%\n", lvl-29, PR_SKILLS[i],sk);
      else
        res+=sprintf("[%3d] %-26s %3d%%\n", lvl, PR_SKILLS[i],sk);
   }
   res += "\nYou have "+who->practice_sessions()+" practice sessions left.\n";
   res += "-------------------------------------\n";

   who->more_string( res );
}
