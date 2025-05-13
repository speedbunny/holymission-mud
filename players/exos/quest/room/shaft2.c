inherit "/room/room";
#include "quest.h"

void reset( int arg ) {
    if( !arg ) {
	set_light( 0 );
	short_desc = "In a shaft";
	long_desc = 
	"The ladder continues further into the darkness.  \
Everything seems to be quite dry, which is odd \
considering how deep you are now.  The darkness \
seems to be growing thicker and heavier.\n";
	dest_dir = ( {
	      ROOM + "shaft1", "up",
	      ROOM + "shaft3", "down",
	  } );
	items = ( {
	      "shaft", "A shaft leads down into the darkness",
	      "ladder", "The ladder is used to traverse the shaft",
	      "darkness",
	      "It seems to be getting darker as you go down",
	      "everything", "It seems to be free of moisture",
	  } );
	smell = "You smell dust and mold.";
    }
    replace_program( "/room/room" );
    ::reset( arg );
}
