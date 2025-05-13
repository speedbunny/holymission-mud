inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "A large windswept open plain stretches out north " +
    "and west of here.  A large forest forms the southern and eastern "+
    "boundary.\n";

  items = ({
    "plain", "A large windswept plain",
    "forest", "It is too thick to enter here",
  });

  dest_dir = ({
    PLAIN + "ruin", "north",
    PLAIN + "plain02", "west",
  });

  ::reset(arg);
  replace_program("room/room");
}

