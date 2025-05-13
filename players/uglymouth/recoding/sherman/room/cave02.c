#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 0 );
  short_desc = "In a dark cave under a dark hill";
  long_desc = "You are walking along a dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. Further on it goes steeply down in a somewhat " 
    + "spiralling fashion. There's a dead end further south.\n";
  dest_dir = ({
    ROOM_DIR + "cave01", "south",
    ROOM_DIR + "cave03", "down",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
    "dead end", "You think you notice a shimmer of light coming from above",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
