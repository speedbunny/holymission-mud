inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Shore road";

  long_desc =
    "Shore road runs northwest here and leads to the coast "+
    "to the southeast.\n";

  dest_dir = ({
    EAST + "shoreroad11", "northwest",
    SHORE + "shore01", "southeast",
  });

  items = ({
    "road", "The road continues northwest",
    "coast", "It is to the southeast",
  });

  replace_program("room/room");
}
