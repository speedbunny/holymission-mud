/*
#include <doorroom.h>
*/
#include "doorroom.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  set_light( 1 );
  short_desc = "A green room.";
  long_desc = "This is an empty green room.\n"
    + "There is a red door in the south wall.\n";
  dest_dir = ({
    "/players/uglymouth/recoding/doors/dr1", "south",
  });
  items = ({
    "red door", "",   // Red door dummy description
  });
  
  /* Set these two functions if the door is can also be approached from
   * this side for the FIRST time (when the rooms are not yet loaded).
   * Otherwise you only have to set the normal room stuff. */
  set_door( "red door" );
  set_door_dependent( "red door", "/players/uglymouth/recoding/doors/dr1" );
  
  replace_program( DOOR_ROOM );
}
