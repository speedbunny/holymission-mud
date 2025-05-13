
/*===========================================================================
	BARBARIAN GREETING --- Used to greet Barbarians
===========================================================================*/

#include "/players/apollo/guild/barb.h"

int main( string str ) {

   object obj;

   obj = present( str, environment( this_player() ) );

   if( !obj ) {
        write( "Sorry, but " + CAP(str) + " is not here to greet.\n" );
	return( 1 );
   }

   if( obj && interactive( obj ) ) {
	if( obj->query_guild() == this_player()->query_guild() ) {

	tell_object( obj, "Barbarian " + CAP( TP->RNAME ) + " slams " +
		this_player()->query_possessive() + " forehead into your " +
		"skull in a secret greeting \nof the Horde!\n" );

	write( "You smash your forehead into the skill of " +
		CAP(str) + " in the greeting of the Horde!\n" );

	say( CAP( TP->RNAME ) + " smashes " + 
		this_player()->query_possessive() + " foreheard into the " +
		"skull of " + CAP(str) + "!\n" );

	return( 1 );

	}

   else {
	write( CAP(str) + " is not a member of the Horde!\n" );
	return( 1 );
   }

   }
}

