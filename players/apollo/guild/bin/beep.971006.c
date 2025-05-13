
/*===========================================================================
	BEEP --- Used to beep a guild member in an emergency
===========================================================================*/

#include "/players/apollo/guild/barb.h"

int main( string str ) {
   
   object obj;

   obj = find_player( str );

   if( !obj ) {
	write( "Sorry, but " + CAP(str) + " is not logged on.\n" );
	return( 1 );
   }

   if( obj->query_guild() != 11 ) {
	write( "You may only beep your guild members.\n" );
	return( 1 );
   }

   tell_object( obj, "<<<  >>> " + CAP(TP->RNAME) + " beeped you!\n" );
   write( "You beeped " + CAP(str) + ". " + CAP(str) + " will be with " +
	  "you as soon as he is available.\n" );

   return 1;

}

