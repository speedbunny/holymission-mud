#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On a lower slope of a dark hill in a dark land.";
  long_desc = "You walk along the lower part of the slope of a dark hill. "
    + "Your feet follow a dirt road through a land of loose sand and dark, "
    + "dry heather. Everything has the colour like a big fire has swept "
    + "over this land recently. You observe the ruins of a house or "
    + "farmstead further uphill to the northeast.\n";
  dest_dir = ({
    ROOM_DIR + "darkld04", "northeast",
    ROOM_DIR + "darkld02", "south",
  });
  items=({ 
    "slope", "It's not steep, but the ground is difficult to walk on",
    "hill", "The first in a chain of hills. It's not high, but you have "
      + "seen steep mountains that had a less dangerous feel about them",
    "road", "It looks like a normal dirt road, although noone has gone it "
      + "for a long time",
    "sand", "It's got the structure of normal sand, but it's dark grey",
    "heather", "Small shrubs of stems and flowers, but they're dark brown",
    "ruins", "Only the lower half of the outer wall is still standing",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
