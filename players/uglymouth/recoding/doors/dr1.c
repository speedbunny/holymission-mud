#include <doorroom.h>
/*
#include "doorroom.h"
*/

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 1, "uglymouth_unique_red_door_key", "/obj/thing", ({
      "set_name", "red key",
      "set_alias", "uglymouth_unique_red_door_key",
      "set_alt_name", "key",
      "set_short", "A red key",
      "set_long", "This is the key belonging to test rooms dr1 and dr2.\n",
      "set_weight", 1,
    }),
  });
  
  // ::reset( arg ); can be anywhere AFTER clone_list and BEFORE set_door().
  ::reset( arg );
  set_light( 1 );
  short_desc = "A blue room.";
  long_desc = "This is an empty blue room.\n"
    + "There is a red door in the north wall.\n";
  hidden_dir = ({
    "/players/uglymouth/recoding/doors/dr2", "north",
  });
  items = ({
    "red door", "", // Red door dummy description.
  });

  // Set the id of the door, used in i.e. open <door> and look at <door>.
  // Make sure you don't use the same id for different doors in one room.
  set_door( "red door" );
  // Set the description of the door here.
  set_door_desc( "red door", "An oak wooden door painted red" );
  // Set the direction to which the door leads here.
  set_door_direction( "red door", "north" );
  // Define if the door has a lock here, and set it locked, or unlocked.
  // You can also set the difficulty of the lock (see userdoc in doorroom.c).
  set_lock_status( "red door", DOOR_LOCKED + 1 );
  // Define here the id of the key that fits the lock on this door.
  set_door_key( "red door", "uglymouth_unique_red_door_key" );
  // Set here all the functions you want called at reset.
  // Note thar if you don't set these the door will not close automatically.
  set_door_reset( "red door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED + 1,
  }) );
  // Set a message to be displayed in both rooms at reset.
  set_door_reset_msg( "red door", "Suddenly the red door swings shut.\n" );
  // By default a message is added to the long_desc displaying for each door
  // whether it is open or closed. Add all doors for which you do not want this
  // message displayed to the argument of the next function.
//  set_invisible_doors( ({ "red door" }) );
  // This copies the door settings to the room at the other side.
  // You don't need it if you make a one-way door.
  set_other_door( "red door" );

  replace_program( DOOR_ROOM );
}
