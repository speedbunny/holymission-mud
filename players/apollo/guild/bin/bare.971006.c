
/*==========================================================================
	BARE (teeth) --- Just an extra
==========================================================================*/

int main( string str ) {

   if( str != "teeth" ) {
	write( "What do you want to bare?!?\n" );
	return 1;
   }

   write( "You bare your teeth and look ready to eat someone alive!\n" );

   say( this_player()->query_name() + " bares " +
	this_player()->query_possessive() + " teeth and looks ready " +
	"to eat you alive!\n" );

   return 1;

}

