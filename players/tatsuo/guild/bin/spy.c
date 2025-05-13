#include "/players/tatsuo/guild/ndef.h"

main( arg )
{
   object room, inv;
   string *dest_dir;
   int    i;
   
   if ( !arg ) {
      write( "In which direction do you want to spy ?\n" );
      return( 1 );
   }

 if(TPL <= 9 ) return printf("You haven't learn this ability yet!!\n"),1;
   if ( TP->query_sp() < SPY_COST ) {
      write( "You're too low on power for spying.\n" );
      return( 1 );
   }
   
   room = environment( TP );
   if ( !room )
      return;
      
   i = 1;
/* fixed by James. backup copy was made 300693 */
   dest_dir = (string *) room->query_room("dest_dir");
   
   while ( i < sizeof( dest_dir ) ) {
      if ( arg == dest_dir[i] ) {
         if ( !(dest_dir[i-1]) ) {
            write( "Somehow you don't manage it to spy " + arg + ".\n" );
            return( 1 );
         }
            
         write( "You spy " + arg + " and see the following:\n\n" );
         dest_dir[i-1]->long();
         room = find_object( dest_dir[i-1] );
         if ( !room )
            return( 1 );
         inv = all_inventory( room ); 
         if ( inv )
            for ( i = 0; i < sizeof( inv ); i++ )
               if ( inv[i] && inv[i]->short() && strlen( inv[i]->short() ) ) 
                  write( inv[i]->short() + ".\n" );
    
         TP->restore_spell_points( -1 * SPY_COST );
         return( 1 );
      }
      i += 2;
   }

   write( "Somehow you don't manage it to spy " + arg + ".\n" );
   return( 1 );
}


