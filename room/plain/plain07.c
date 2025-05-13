inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "A large open plain. There is a big tree to the west.\n";

  items = ({
    "plain", "It is quite large",
    "tree", "There is a big tree to the west",
  });

  dest_dir = ({
    PLAIN + "plain10", "north",
    PLAIN + "plain03", "east",
    PLAIN + "big_tree", "west",
    PLAIN + "plain05", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}

