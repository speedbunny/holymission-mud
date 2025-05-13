#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On the narrow gravel path of a deserted cemetery.";
  long_desc = "You walk on the narrow gravel path of a deserted cemetary. "
    + "West from here lies the entrance of the cemetery. The path continues "
    + "to the east. To the north and south you see graves.\n";
  dest_dir=({
    ROOM_DIR + "cemetry1", "west",
    ROOM_DIR + "cemetry3", "east",
  });
  hidden_dir = ({
    ROOM_DIR + "grave01", "north",
    ROOM_DIR + "grave02", "south",
  });
  items=({
    "path", 
      "A narrow path of dull red gravel. Weeds are slowly growing over it",
    "cemetery", "Noone has been here in a long time. Weeds grow wildly "
      + "between the graves",
    "entrance", "A rusty iron gateway stands open. Beyond lies a dirt road",
    "graves", "There's one to the north and one to the south. "
      + "Step closer to see more details",
  });
  ::reset();
  replace_program( "room/room" );
}
