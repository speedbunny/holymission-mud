#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On the narrow gravel leading to a small chapel.";
  long_desc = "You walk on the narrow gravel path of a deserted cemetary. "
    + "East from here a doorway gives access to a small chapel. The path "
    + "leads back west to the other side of the cemetary. To the north and "
    + "south you see graves.\n";
  dest_dir=({
    ROOM_DIR + "cemetry5", "west",
    ROOM_DIR + "chapel1", "east",
  });
  hidden_dir = ({
    ROOM_DIR + "grave09", "north",
    ROOM_DIR + "grave08", "south",
  });
  items=({
    "path", 
      "A narrow path of dull red gravel. Weeds are slowly growing over it",
    "cemetery", "Noone has been here in a long time. Weeds grow wildly "
      + "between the graves",
    "chapel", "This used to be a place for contemplation and prayer. "
      + "It's in a bad state",
    "doorway", "There must once have been a door hanging from the hinges",
    "graves", "There's one to the north and one to the south. "
      + "Step closer to see more details",
  });
  ::reset();
  replace_program( "room/room" );
}
