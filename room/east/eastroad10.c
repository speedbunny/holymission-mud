inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="East road";

  long_desc =
    "East road runs north-south here. The is a small keep to "+
    "the west.\n";

  dest_dir = ({
    EAST + "eastroad11", "northeast",
    "/players/gareth/guild/rooms/castle", "west",
    EAST + "eastroad09", "south",
  });

  items = ({
    "road", "The road continues both north and south",
    "keep", "It looks like it could be used for training",
  });

  replace_program("room/room");
}
