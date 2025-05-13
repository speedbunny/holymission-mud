#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On a lower slope of a dark hill in front of a tower.";
  long_desc = "You walk along the lower part of the slope of the third " 
    + "dark hill. To the northeast the road leads to a black tower. You "
    + "notice a cloud of black spots around its spire. The road continues "
    + "southeast. A narrow path leads north to the ruins of another farm. "
    + "The vegetation in this hill is less dense and you think you could "
    + "make your way to the top in a northeastern direction. Small sharp "
    + "stones are scattered everywhere.\n";
  dest_dir = ({
    ROOM_DIR + "vtower01", "northeast",
    ROOM_DIR + "darkld09", "southeast",
    ROOM_DIR + "darkld12", "north",
  });
  hidden_dir = ({
    ROOM_DIR + "darkld11", "northwest",
  });
  items=({ 
    "slope", "The slope of this hill looks less unfriendly, but you fear "
      + "that this is only the calm before the storm",
    "hill", "The last in a chain of hills. Although its vegetation is less "
      + "hostile, the vicinity of the black tower makes it feel unsafe",
    "road", "It has been hewn out in the rock surface. The many small, "
      + "sharp stones make it difficult to travel though",
    "tower", "A tall black tower build of thick stones. It probably "
      + "functioned as residence and defense structure for the local rulers",
    "cloud", "A cloud of flying animals",
    "spots", "They seem somewhat small for birds..",
    "vegetation", "Loosely spread out over the hill are some dark brown "
      + "heather shrubs, mixed with some patches of tall grey grass",
    "heather", "Small shrubs of stems and flowers, but they're dark brown",
    "grass", "It reaches to your waste and looks completely dried out",
    "path", "Just a winding strip of bare rock among the vegetation.",
    "ruins", "The main building of the farm is destroyed, but one of the "
      + "outhouses has partly survived the destruction",
    "farm", "The main building of the farm is destroyed, but one of the "
      + "outhouses has partly survived the destruction",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
