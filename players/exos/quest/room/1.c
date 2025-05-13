inherit "/room/room";
#include "quest.h"

void reset( int arg ) {
    if( !arg ) {
	set_light( -4 );
	short_desc = "Cave Entrance";
	long_desc = 
	"You are in a dark cave.  It is very cold and dry.  \
The walls appear to be naturally hewn stone.  You wonder \
if man has ever ventured here before.\n";
	dest_dir = ( {
	      ROOM + "pit", "west",
	      ROOM + "2", "east",
	  } );
	items = ( {
	      "cave", "A dark natural cave",
	      "wall", "The wall is naturally hewn stone",
	      "walls", "The walls are naturally hewn stone",
	      "stone", "The stone does not seem to have been worked",
	  } );
	smell = "You smell dust and mold.";
    }
    replace_program( "/room/room" );
    ::reset( arg );
}
