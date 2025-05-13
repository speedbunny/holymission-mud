inherit "/guild/prac_monster";

#define PR_SPELLS ({ "fire shuriken", "shadow door", "summon wind", \
                     "acid blast", "acid rain",\
                     "freeze", "paralyze" })
#define PR_SPELLS_LVL ({ 5, 8, 11, 13, 16, 25, 31 })

#define TP this_player()

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name("Hawamuku Ajakudji");
   set_alias( "ajakudji-san" );
   set_alt_name( "ajakudji-San" );
   set_level(70);
   set_short("A very learned ninja");
   set_long(
      "This obviously is the most learned ninja you have ever seen. He is\n"+
      "even better than the shogun of the guild and he has spent all his\n"+
      "life to get knowledge of the ninja-kis. Fortunately he has decided to\n"+
      "make his knowledge popular, and he will be eager give you practice.\n");

   transfer(clone_object( "/players/patience/guild/nweap/sai" ), this_object());
   command( "wield sai" );

   set_chance( 100 );
   set_spell_mess1("Ajakudji-San hits his opponent CRITICALLY at the head !!!");
   set_spell_mess2("Ajakudji-San hits you CRITICALLY at the head !!!" );
   set_spell_dam( 100 );

   set_dead_ob( "/players/patience/eastMonst/monst_died" );

   set_language_skill(1,100);
   set_speaks_in(1);
}

init()
{
   ::init();

   add_action( "_up", "up" ); 
}

_up()
{
   if ( this_object()->query_attack() == this_player() ) {
      write( "Ajakudji-San blocks the way back up !!!\n" );
      return( 1 );
   }

   return( 0 );
}

// --------------------------------------------------------------------------
int advance_spell( object who, string sn, string fn, int max_sk )
{
   int res;

   if ( who->query_guild() != 8 ) {
      ltell( who, "says:", "I will advise ninjas only !\n", this_object() );
      return( 1 );
   }

   if ( !(who->speaks_in() == 1 && who->language_skill(1) > 80) ) {
      write( "Ajakudji-San has an indifferent look !\n" );
      return( 1 );
   }

   if ( member_array( sn, PR_SPELLS ) < 0 ) {
      ltell( who, "says:", "I do not know of such a spell !\n",
                   this_object() );
      return( 1 );
   }

   res = ::advance_spell( who, sn, fn, 95 );
   if ( res < 0 )
      ltell( who, "says:", "You cannot advance any further !\n",
                   this_object() );
   else
     tell_object(who,"Ajakudji-San shows you more mysteries of this spell !\n");

   return( res );
}

int learn_spell( object who, string sn, string fn, int max_sk )
{
   int res, idx;

   if ( who->query_guild() != 8 ) {
      ltell( who, "says:", "I will advise ninjas only !\n", this_object() );
      return( 1 );
   }

   if ( !(who->speaks_in() == 1 && who->language_skill(1) > 80) ) {
      write( "Ajakudji-San has an indifferent look !\n" );
      return( 1 );
   }

   idx = member_array( sn, PR_SPELLS );
   if ( idx < 0 ) {
      ltell( who, "says:", "I do not know of such a spell !\n",
                   this_object() );
      return( 1 );
   }
   if ( PR_SPELLS_LVL[idx] > (TP->query_level()+TP->query_legend_level()) ) {
      ltell( who, "says:", "Gain more knowledge first, fellow !\n",
                   this_object() );
      tell_object( who, "Ajakudji-San pats you on your head.\n" );
      return( 1 );
   }

   res = ::learn_spell( who, sn, fn, 95 );
   if ( res < 0 )
     ltell(who,"Ajakudji-San says:","Somehow I cannot teach you this spell !\n",
                   this_object() );
   else
     tell_object(who,"Ajakudji-San shows you the mysteries of this spell !\n");

   return( res );
}

void list_spells( object who )
{
   string res;
   int    i, max, sk;

   max = sizeof( PR_SPELLS );
   res = "-----------------------------\n";
   for ( i = 0; i < max; i++ ) {
      res += sprintf( "[%2d] %-20s %3d\n", PR_SPELLS_LVL[i],
                        PR_SPELLS[i], who->get_spell_skill( PR_SPELLS[i] ) );
   }
   res += "-----------------------------\n";

   who->more_string( res );
}
