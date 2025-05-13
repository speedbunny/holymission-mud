#define    TP     (this_player())

help_skills( arg )
{
   if ( arg == "fireshuriken" ) {
      if ( TP->get_skill( "fire_shuriken" ) ) {
         cat( "/players/patience/guild/sorcerer_spells/fire_shuriken.txt" );
         return( 1 );
      }
   }
   else if ( arg == "summon wind" ) {
      if ( TP->get_skill( "summon_wind" ) ) {
         cat( "/players/patience/guild/sorcerer_spells/summon_wind.txt" );
         return( 1 );
      }
   }
   else if ( arg == "earthgrip" ) {
      if ( TP->get_skill( "earth_grip" ) ) {
         cat( "/players/patience/guild/sorcerer_spells/earth_grip.txt" );
         return( 1 );
      }
   }
   else if ( arg == "freeze" ) {
      if ( TP->get_skill( "freeze" ) ) {
         cat( "/players/patience/guild/sorcerer_spells/freeze.txt" );
         return( 1 );
      }
   }

   write( "You don't know anything about this spell.\n" );

   return( 1 );
}
