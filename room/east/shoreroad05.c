inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Shore road";

  long_desc =
    "Shore road runs northwest-southeast here and "+
    "passes a forest to the southwest.\n";

  dest_dir = ({
    EAST + "shoreroad04", "northwest",
    EAST + "shoreroad06", "southeast",
  });

  items = ({
    "road", "The road continues both northwest and southeast",
    "forest", "It is too thick to enter",
  });

  replace_program("room/room");
}
