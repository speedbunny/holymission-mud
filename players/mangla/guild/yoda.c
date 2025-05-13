inherit "/guild/prac_monster";

#include "/players/mangla/defs.h"

#define PR_SPELLS ({ "lightning",\
                     "brainstorm",\
                     "terror",\
                     "fearall",\
                     "spread",\
                     "discord",\
                     "bolt",\
                     "noattack",\
                  })

#define PR_ABIL   ({ })

#define PR_SKILLS ({ "parry",\
                     "multi-wield",\
                  })

#define SPELL_MASTER   "/spells/master"
#define ABILITY_MASTER "/abilities/master"
#define SKILL_MASTER   "/masters/skills"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_race( "yga" );
   set_name("Yoda");
   set_alias( "yoda" );
   set_level(70);
   set_ep(0);
   set_dex(100);
   set_short("Yoda, Jedi Master");
   set_long(
            "Yoda has travelled very far and has collected a lot of knowledge\n"+
            "in his search for excellence. He can teach you some of this\n"+
            "knowledge is you will 'prac' wth him.\n");

   set_number_of_arms( 2 );

   transfer(clone_object(PATH+"guild/lightsaber"),TO);
   transfer(clone_object(PATH+"guild/lightsaber"),TO);
   command( "wield handle" );
   command( "wield handle 2" );

   set_chance( 80 );
   set_spell_mess1("Yoda casts a lightning bolt!");
   set_spell_mess2("Yoda nails you with a bolt of lightning!" );
   set_spell_dam( 100 );

   set_spells( PR_SPELLS );
   set_abilities( PR_ABIL );
   set_skills( PR_SKILLS );
}

int query_show_short( )
{
   return( 1 );
}

// ------------ SPELLS ------------------------------------------------------
int advance_spell( object who, string sn, string fn, int max_sk )
{
   int res;

   if ( who->query_guild() != 4 ) {
      ltell( who, "says:", "You are not of the force!\n", TO );
      return( 1 );
   }

   res = ::advance_spell( who, sn, fn, 95 );

   if ( res == -3 ) 
      ltell( who, "says:", "I am not familiar with that spell.\n", TO );
   else if ( res == -2 )
      ltell( who, "says:", "You will have to gain more experience.\n",TO);
   else if ( res < 0 )
      ltell( who, "says:", "I cannot teach you more. You are strong.\n",
                   TO );
   else
     tell_object(who,"Yoda passes on more knowledge to you.\n");

   return( res );
}

int learn_spell( object who, string sn, string fn, int max_sk )
{
   int    res;

   if ( who->query_guild() != 4 ) {
      ltell( who, "says:", "You are not of the force!\n", TO );
      return( 1 );
   }

   res = ::learn_spell( who, sn, fn, 95 );
   if ( res == -4 ) {
      ltell( who, "says:", "You must gain more knowledge first.\n",
                   TO );
      tell_object( who, "Yoda wishes you luck.\n" );
   }
   else if ( res == -3 ) 
      ltell( who, "says:", "I am not versed in that field.\n", TO );
   else if ( res == -2 )
      ltell( who, "says:", "You must earn more experience.\n",TO);
   else if ( res < 0 )
     ltell(who,"says:","I cannot teach you that spell.\n",
                   TO );
   else
     tell_object(who,"Yoda teaches you the spell.\n");

   return( res );
}

// ------------ ABILITIES ---------------------------------------------------
int advance_ability( object who, string sn, string fn, int max_sk )
{
   int res;

   if ( who->query_guild() != 4 ) {
      ltell( who, "says:", "You are not at one with the force!\n", TO );
      return( 1 );
   }

   res = ::advance_ability( who, sn, fn, 95 );
   if ( res == -3 ) 
      ltell( who, "says:", "I am unaware of such a spell.\n", TO );
   else if ( res == -2 )
      ltell( who, "says:", "You must earn more experience.\n",TO);
   else if ( res < 0 )
      ltell( who, "says:", "You cannot advance any further.\n",
                   TO );
   else
    tell_object(who,"Yoda teaches you more of that ability.\n");

   return( res );
}

int learn_ability( object who, string sn, string fn, int max_sk )
{
   int    res;

   if ( who->query_guild() != 4 ) {
      ltell( who, "says:", "You are not at one with the force!\n", TO );
      return( 1 );
   }

   res = ::learn_ability( who, sn, fn, 95 );
   if ( res == -4 ) {
      ltell( who, "says:", "You must gain more knowledge first.\n",
                   this_object() );
      tell_object( who, "Yoda wishes you luck.\n" );
   }
   else if ( res == -3 ) 
      ltell( who,"says:","I am unfamiliar with that ability.\n", TO );
   else if ( res == -2 )
      ltell( who, "says:", "You must gain more experience first.\n",TO);
   else if ( res < 0 )
     ltell(who,"says:","I am unable to teach you this ability.\n",
                   TO );
   else
     tell_object(who,"Yoda teaches you this ability.\n");

   return( res );
}

// ------------ SKILLS -------------------------------------------------------
int advance_skill( object who, string sn, int max_sk )
{
   int res;

   if ( who->query_guild() != 4 ) {
      ltell( who, "says:", "You are not at one with the force.\n", TO );
      return( 1 );
   }

   res = ::advance_skill( who, sn, 100 );
   if ( res == -3 ) 
      ltell( who, "says:", "I do not know of such a spell.\n", TO );
   else if ( res == -2 )
      ltell( who, "says:", "You must earn more experience.\n",TO);
   else if ( res < 0 )
      ltell( who, "says:", "I have taught you all I can.\n",
                   this_object() );
   else
    tell_object(who,"Yoda teaches more tricks of the skill.\n");

   return( res );
}

int learn_skill( object who, string sn, int max_sk )
{
   int    res;

   if ( who->query_guild() != 4 ) {
      ltell( who, "says:", "You are not at one with the force.\n", TO );
      return( 1 );
   }

   res = ::learn_skill( who, sn, 100 );
   if ( res == -4 ) {
      ltell( who, "says:", "You must gain more experience first.\n",
                   TO );
      tell_object( who, "Yoda wishes you luck.\n" );
   }
   else if ( res == -3 ) 
      ltell( who,"says:","I am not versed in such knowledge.\n", TO );
   else if ( res == -2 )
      ltell( who, "says:", "You must earn more experience first.\n",TO);
   else if ( res < 0 )
     ltell(who,"says:","For some reason I cannot teach you this skill.\n",
                   TO );
   else
     tell_object(who,"Yoda teachs you this skill.\n");

   return( res );
}

// ---------- THE LIST -------------------------------------------------------
void list_prac( object who )
{
   if ( who->query_guild() != 4 ) {
      write( "You are not at one with the force.\n" );
      return;
   }

   ::list_prac( who );
}
