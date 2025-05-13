/*  This is the East Wing  
 * 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */

#include <doorroom.h>
#include "/players/tamina/defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if (arg) return ;

  set_light(0);
  short_desc = "East Wing ";
  long_desc = "Here the corridor turns to the north, but also ends in "
    + "a door leading to the east.  Ahead of you, light spills onto "
    + "the stone slabs.\n";
  dest_dir = ({
    CROOMS + "ewing5","north",
    CROOMS + "ewing3","west",
  });
  hidden_dir = ({
    CROOMS + "ebed1", "east",
  });
  items = ({
    "door", "dummy door description",
  });
  property = ({"no_knock"});

  set_door( "door" );
  set_door_desc( "door",
    "This appears to be a well-used door, with a strong lock" );
  set_door_direction( "door", "east" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "keym1" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "The door slams shut.\n" );
  set_other_door( "door" );
  replace_program( DOOR_ROOM );
}
