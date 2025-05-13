#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  clone_list = ({ 
    1, 6, "troul", MON_DIR + "troul", 0,
  });

  set_light( -1 );
  short_desc = "In a very dark cave under a dark hill";
  long_desc = "You are walking down a very dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. The cave continues southwest and east.\n";
  dest_dir = ({
    ROOM_DIR + "cave04", "east",
    ROOM_DIR + "cave06", "southwest",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
