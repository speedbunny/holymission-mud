
/*==========================================================================
	FLEX (muscles) --- Just an extra
==========================================================================*/

int main( string str ) {

   if( str != "muscles" ) {
	write( "What do you want to flex?!?\n" );
	return 1;
   }

   write( "You flex your muscles to everyone in the room.\n" );

   say( this_player()->query_name() + " flexes " +
	this_player()->query_possessive() + " muscles.\n" );

   return 1;

}

