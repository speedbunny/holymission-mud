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
    EAST + "road04", "east",
    EAST + "road02", "west",
    FIELDS + "crop03", "south",
  });

  items = ({
    "road", "The road stretches from town to the east",
    "crops", "The field is full of them",
  });

  replace_program("room/room");
}
