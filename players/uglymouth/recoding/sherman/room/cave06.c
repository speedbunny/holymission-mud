#include "../defs.h"

inherit "room/room";

void reset( int arg ) {

  set_light( -1 );
  short_desc = "In a very dark cave under a dark hill";
  long_desc = "You are walking down a very dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. Once again, the cave makes a steep drop down here, "
    + "but continues northeast on this level as well.\n";
  dest_dir = ({
    ROOM_DIR + "cave05", "northeast",
    ROOM_DIR + "cave07", "down",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
