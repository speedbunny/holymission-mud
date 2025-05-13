#include "../defs.h"

inherit "room/room";

void reset( int arg ) {

  set_light( -1 );
  short_desc = "In a very dark cave under a dark hill";
  long_desc = "You are walking down a very dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. With a careful climb along the foot holds in the "
    + "rock you could descend to a lower level of the cave. The cave also "
    + "continues northeast from here.\n";
  dest_dir = ({
    ROOM_DIR + "cave10", "northeast",
    ROOM_DIR + "cave08", "down",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
    "foot holds", "In fact they are little more than shallow holes",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
