inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="East road";

  long_desc =
    "East road runs north-south here.\n";

  dest_dir = ({
    EAST + "eastroad06", "north",
    EAST + "eastroad04", "south",
  });

  items = ({
    "road", "The road continues both north and south",
  });

  replace_program("room/room");
}
