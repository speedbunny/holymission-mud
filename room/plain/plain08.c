inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "You are standing at the northeastern edge of a large, " +
    "windswept open plain. To the south and west you can " +
    "see the rolling grasses stretch out.\n";

  dest_dir = ({
    PLAIN + "ruin", "south",
    PLAIN + "plain06", "west",
  });

  items = ({
    "plains", "Stretching out the west and south",
    "plain", "Stretching out the west and south",
    "grasses", "They grow in the plains",
  });

  ::reset(arg);
  replace_program("room/room");
}

