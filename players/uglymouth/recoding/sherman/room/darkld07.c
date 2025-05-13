#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On the slope of the second dark hill in a dark land.";
  long_desc = "You walk along the slope of the second dark hill. "
    + "This hill is as desolate a place as the others. The road continues "
    + "north and southwest towards the valleys between this hill and the "
    + "other two hills respectively. A small, overgrown path leads east "
    + "up the hill towards the ruins of another farm.\n";
  dest_dir = ({
    ROOM_DIR + "darkld06", "southwest",
    ROOM_DIR + "darkld09", "north",
    ROOM_DIR + "darkld08", "east",
  });
  items=({ 
    "slope", "It's not steep, but the ground is difficult to walk on",
    "hill", "The second in a chain of hills. The other hills are to the "
      + "north and to the west. Each looks equally triste",
    "road", "It looks like a normal dirt road. Southwest it is interrupted "
      + "by a set of stepping stones that lead trough a swamp",
    "ruins", "It looks like another burned down farm",
    "farm", "It looks like another burned down farm",
    "swamp", 
      "A narrow patch of decaying wetland where once a fresh stream ran",
    "path", "A small line of different vegetation shows the way",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
