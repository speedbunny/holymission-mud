
/*============================================================================
		BARBARIAN SOUL
============================================================================*/

#include "/players/apollo/forguild/barb.h"

int guild;
string barbline;

int id( string str ) {
   return( str == "barbarian soul" || str == "guildsoul" );
}

int get() { return 1; }

int put() { return 1; }

int drop( string str ) { return 1; }

string query_barb_line() { return barbline; }

int set_barb_line(string str) {
	barbline=str;
}

void long() {
   write( "This is the Barbarian Soul.\n" );
}

void init() {

   set_barb_line( "On" );

   if( this_player()->query_invis() && this_player()->query_immortal() ) { }
   else {
	CHAT( 11, "<= Barbarian => " + CAP( RNAME ) + 
		" howls at the world as " + this_player()->query_pronoun() +
		" returns to battle!\n" );
   }

   if( !this_player()->query_immortal() ) {
	write_file( GLOGS + "LOGON", CAP( RNAME ) + " logged on at " +
		ctime( time() ) + "\n" );
	write_file( MEMBERS + RNAME + ".o", "\n" + CAP( RNAME ) +
		" is a guild member.\n \n" );
   }
   else {
	write_file( GLOGS + "WIZLOGON", CAP( RNAME ) + " logged on at " +
		ctime( time() ) + "\n" );
/*
	remove_file( GLOGS + RNAME + ".o" );
*/
	write_file( GLOGS + RNAME + ".o", "\n" );
   }

   AA( "do_quit", "quit" );
   AA( "_filter", "", 1 );

}

int _filter( string str ) {

   string theverb;

   theverb = ( string )query_verb();

   if( theverb[0] == 39 ) return 0;
   if( theverb == "dest" ) return 0;
   if( FS( BIN + theverb + ".c" ) > 0 )
	if( ( BIN + theverb ) -> main(str) )
	   return 1;
	else return 0;
   if( theverb == "barb/" || theverb == "barb=" ) {
	( BIN + "barb" ) -> main( str );
	return 1;
   }

}

int do_quit() {

   object soul;

   soul = present( "guildsoul" , TP );

   if( this_player()->query_invis() && this_player()->query_immortal() ) { }
   else{
	CHAT( 11, "<= Barbarian => " + CAP( RNAME ) +
		" lets out a huge cry as " + this_player()->query_pronoun() +
		" leaves the battle field.\n" );
   }

   if( !this_player()->query_immortal() ) {
	write_file( GLOGS + "LOGOFF", CAP( RNAME ) + " logged off at " +
		ctime( time() ) + "\n" );
   }
   else {
	write_file( GLOGS + "WIZLOGOFF", CAP( RNAME ) + " logged off at " +
		ctime( time() ) + "\n" );
   }

   if( soul ) { 
	destruct( soul );
   }

   return 0;
}


