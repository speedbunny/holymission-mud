
/*==========================================================================
	BEAT (chest) --- Just an extra 
==========================================================================*/

int main( string str ) {

   if( str != "chest" ) {
	write( "What do you want to beat?!?\n" );
	return 1;
   }

   write( "You beat your hands on your chest and let out a " +
	  "bloodcurling howl!\n" );

   say( this_player()->query_name() + " beats " +
	this_player()->query_possessive() + " hands on " +
	this_player()->query_possessive() + " chest and lets out a " +
	"bloodcurling howl!\n" );

   return 1;

}

