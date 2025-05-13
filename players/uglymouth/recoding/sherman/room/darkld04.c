#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On the higher slope of a dark hill in a dark land.";
  long_desc = "You walk along the higher part of the slope of a dark hill. "
    + "Right next to the raod you walk on are the ruins of a farm. It was "
    + "burned to the ground long ago, with only small parts of its walls "
    + "still standing up black against the dark grey soil of the hill. The "
    + "road goes up northwest to the top, and goes down the hill both to "
    + "the southwest and to the east.\n";
  dest_dir = ({
    ROOM_DIR + "darkld05", "northwest",
    ROOM_DIR + "darkld06", "east",
    ROOM_DIR + "darkld03", "southwest",
  });
  items=({ 
    "slope", "It's not steep, but the ground is difficult to walk on",
    "hill", "The first in a chain of low, dark hills. There are more hills "
      + "to the east. Far northeast you see the spire of a tower",
    "road", "It looks like a normal dirt road, although noone has gone it "
      + "for a long time",
    "ruins", "This once was a small farm, but apart from some charred "
      + "rubble and broken beams there is nothing left of it.",
    "farm", "This once was a small farm, but apart from some charred "
      + "rubble and broken beams there is nothing left of it.",
    "soil", "It's got the structure of normal sand, but it's dark grey",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
