inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "Little life can be seen this huge open plain, " +
    "merely scrub vegetation and the occasional small " +
    "furry animal. To the east lie the remains of " +
    "an old building.\n";

  dest_dir = ({
    PLAIN + "plain06", "north",
    PLAIN + "ruin", "east",
    PLAIN + "plain07", "west",
    PLAIN + "plain02", "south",
  });

  items = ({
    "plain", "A large open plain",
    "vegetation", "Only scrub vegetation grows on this huge open plain",
    "remains", "There is a crumbling old ruin to the east",
    "building", "There is a crumbling old ruin to the east",
  });

  ::reset(arg);
  replace_program("room/room");
}
