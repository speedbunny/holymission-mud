inherit "/room/room";
#include "quest.h"

status _letgo( string str );

void reset( int arg ) {
    if( !arg ) {
	set_light( -2 );
	short_desc = "Bottom of a shaft";
	long_desc = 
	"The ladder ends here, but the shaft continues down.  \
It looks like the only way down is also the fastest way.  \
Question is, are you brave (or foolish) enough to let \
go of the ladder?\n";
	dest_dir = ( {
	      ROOM + "shaft3", "up",
	  } );
	items = ( {
	      "shaft", "A shaft leads down into the darkness",
	      "ladder",
	      "The ladder ends here, looks like you will \
have to let go to go down",
	      "darkness", "It is extremely dark now",
	  } );
	smell = "You smell dust and mold.";
    }
    ::reset( arg );
}

void init() {
    ::init();
    add_action( "_letgo", "let" );
}

status _letgo( string str ) {
    if( str != "go" && str != "go of ladder" )
	return ( 0 );
    write( "You let go and fall into nothingness.\n" );
    this_player()->move_player(
      "down the hard way#/players/exos/quest/room/pit" );
    ( ROOM + "pit" )->crash( this_player() );
    return ( 1 );
}
