/* upper_hall.c
 * Recode - Exos 961025
 * Uglymouth, 970818: Recoded to use /room/doorroom.c; improved readability.
 */

#include "walker.h"
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int flag ) {
    ::reset( flag );
    //     if( flag ) return;

    set_light( 1 );
    short_desc = "In the upper hall of the walking castle";
    long_desc =
    "You are in the upper hall of the walking castle.\n" +
    "To the east you see a door leading into a bedroom,\n" +
    "and to the south a walkway leads above the castle yard\n" +
    "to a room with many windows. Stairs go up and down.\n" + 
    "A metal door has been set into the thick wall to the north.\n";
    dest_dir = ({
      "/players/padrone/walker/bedroom", "east",
      "/players/padrone/walker/walkway", "south",
      "/players/padrone/walker/main_hall", "down",
      "/players/padrone/walker/loft", "up",
    });
    hidden_dir = ({
      "/players/padrone/walker/vault", "north",
    });
    items = ({
      "door", "You mean the 'metal door'?",
      "metal door", "dummy door description",
    });

    set_door( "metal door" );
    set_door_desc( "metal door", 
      "This is a solid looking metal door.\n" 
      + "Maybe it leads to a vault of some sort?\n"
      + "There is a big sign on the door, "
      + "saying \"NO ENTRANCE! KEEP OUT!\".\n" 
      + "It has a bullet-proof lock in it" );
    set_door_direction( "metal door", "north" );
    set_lock_status( "metal door", DOOR_LOCKED );
    set_door_key( "metal door", "walkervault" );
    set_door_reset( "metal door", ({
	"set_door_status", DOOR_CLOSED,
	"set_lock_status", DOOR_LOCKED,
      }) );
    set_door_reset_msg( "metal door", "The metal door slams shut!\n" );
    set_other_door( "metal door" );
    replace_program( DOOR_ROOM );
}

