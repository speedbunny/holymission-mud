#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On a dirt road to a dark land.";
  long_desc = "You walk on a wide dirt road that run. To the south the road "
    + "ends at the entrance of an abandoned cemetery. to the north the land "
    + "becomes dark and all vegetation seems to turned in various shapes of "
    + "dark brown, dark grey, dark green and black. Further north the land "
    + "slopes up towards some hills.\n";
  dest_dir = ({
    ROOM_DIR + "darkld02", "north",
    ROOM_DIR + "cemetry1", "south",
  });
  items=({ 
    "road", "It looks like a normal dirt road, although noone has gone it "
      + "for a long time",
    "cemetery", 
      "It doesn't look that big, but it has a dark atmosphere about it",
    "vegetation", "It's all dark and consists solely of plants that can "
      + "survive under harsh condition",
    "hills", 
      "They seem to be some kind of downs. They look black and forbidding",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
