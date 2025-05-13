inherit "/room/room";
#include "quest.h"

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "Top of a shaft";
	long_desc = 
	"You are at the top of a deep, dark shaft.  \
A ladder leads down into the darkness.  You probably \
need a real strong light source to continue.\n";
	dest_dir = ( {
	      "/players/exos/workroom", "up",
	      ROOM + "shaft2", "down",
	  } );
	items = ( {
	      "shaft", "A shaft leads down into the darkness",
	      "ladder", "The ladder is used to traverse the shaft",
	      "darkness",
	      "Looks pretty dark, you might need something bright",
	  } );
	smell = "You smell dust and mold from below you.";
    }
    replace_program( "/room/room" );
    ::reset( arg );
}
