inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "A large bare open plain stretches out in all " +
    "directions from here. The view seems to remain " +
    "the same; nothing breaks its monotony.\n";

  items = ({
    "plain", "The plain is wide",
    "view", "You see the plains to the east and west, a forest "+
      "to the south and more trees to the north",
    "forest", "It is to the south",
    "trees", "The ones to the north are different than the forest",
  });

  dest_dir = ({
    PLAIN + "plain11", "north",
    PLAIN + "plain08", "east",
    PLAIN + "plain10", "west",
    PLAIN + "plain03", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}

