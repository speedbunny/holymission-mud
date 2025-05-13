inherit "/room/room";
#include "quest.h"

void reset( int arg ) {
    if( !arg ) {
	set_light( -1 );
	short_desc = "In a shaft";
	long_desc = 
	"The ladder continues further into the darkness.  \
It is growing considerably cooler now, but surprisingly \
it is still rather dry.  You wonder when the shaft will end.\n";
	dest_dir = ( {
	      ROOM + "shaft2", "up",
	      ROOM + "shaft4", "down",
	  } );
	items = ( {
	      "shaft", "A shaft leads down into the darkness",
	      "ladder", "The ladder is used to traverse the shaft",
	      "darkness",
	      "It seems to be getting darker as you go down",
	  } );
	smell = "You smell dust and mold.";
    }
    replace_program( "/room/room" );
    ::reset( arg );
}
