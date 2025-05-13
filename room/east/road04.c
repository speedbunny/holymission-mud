inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="East road";

  long_desc =
    "East road runs east-west here and heads past some crops "+
    "to the south.\n";

  dest_dir = ({
    EAST + "road05", "east",
    EAST + "road03", "west",
    FIELDS + "crop04", "south",
  });

  items = ({
    "road", "The road stretches from town to the east",
    "crops", "The field is full fo them",
  });

  replace_program("room/room");
}
