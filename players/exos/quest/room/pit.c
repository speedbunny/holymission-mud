inherit "/room/room";
#include "quest.h"

status crash( object obj );

void reset( int arg ) {
    if( !arg ) {
	set_light( -3 );
	short_desc = "Bottom of the pit";
	long_desc = 
	"You are at the bottom of the pit.  It is very dark now.  \
It is still rather dry, but quite cold now.  You wonder \
just how deep you are.  A cave opens to the east.\n";
	dest_dir = ( {
	      ROOM + "1", "east",
	  } );
	items = ( {
	      "pit", "The pit you came in through",
	      "cave", "A cave entrance is to the east",
	  } );
	smell = "You smell dust and mold.";
    }
    ::reset( arg );
}

status crash( object obj) {
    write( "You land with a loud THUD.\n");
    tell_room( this_object(), obj->query_name() +
      " lands with a loud THUD.\n" );
    obj->reduce_hit_point( 50 );
    return ( 1 );
}
