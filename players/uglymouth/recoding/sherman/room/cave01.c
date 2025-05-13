#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 0 );
  short_desc = "At the beginning of a dark cave under a dark hill";
  long_desc = "You stand at the beginning of a dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. It runs further down into a more or less northern " 
    + "direction. Above you lie the ruins of a farm.\n";
  dest_dir = ({
    ROOM_DIR + "darkld08", "up",
    ROOM_DIR + "cave02", "north",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
    "ruins", "You should go up to see them",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
