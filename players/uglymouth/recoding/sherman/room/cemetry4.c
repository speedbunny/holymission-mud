#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "Where two narrow gravel paths of a deserted cemetery meet.";
  long_desc = "You stand at a crossing of gravel paths. The south path goes "
    + "on only for a short distance. Further away west you notice the "
    + "entrance of the cemetery, and further away east you distinguish "
    + "a small chapel. A grave lies to the north.\n";
  dest_dir=({
    ROOM_DIR + "cemetry3", "west",
    ROOM_DIR + "cemetry5", "east",
    ROOM_DIR + "cemetry7", "south",
  });
  hidden_dir = ({
    ROOM_DIR + "grave05", "north",
  });
  items=({
    "paths", 
      "Narrow paths of dull red gravel. Weeds are slowly growing over it",
    "entrance", "An open gateway leads out of this depressing place",
    "cemetery", "Here at the center it really feels like a depressing place",
    "chapel", 
      "It's a small building in a hopeless battle with the forces of time",
    "grave", 
      "A proper grave lies to the north. Step closer to see more details",
  });
  ::reset();
  replace_program( "room/room" );
}
