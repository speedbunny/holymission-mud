
#include "/players/tatsuo/guild/ndef.h"
main( arg )
{
   int i;
   
   if ( set_light(0) < 1 ) {
      if ( TP->query_sp() >= LOOK_COST ) {
         for ( i = 0; i < sizeof( all_inventory(TP) ); i++ )
            if ( all_inventory(TP)[i]->short() )
               write( all_inventory(TP)[i]->short()+".\n" );
         TP->restore_spell_points( LOOK_COST*-1 );
      }
      else
         write( "You are too low on power. So you only see darkness.\n" );
   
      return( 1 );
   }
   
   return( 0 );
}


