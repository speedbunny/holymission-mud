inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "A large open plain stretches off to the north, " +
    "east and south, while a thick, impenetrable " +
    "forest blocks any exit to the west.\n";

  dest_dir = ({
    PLAIN + "plain12", "north",
    PLAIN + "plain06", "east",
    PLAIN + "plain07", "south",
  });

  items = ({
    "plain", "The plain opens up more to the south",
    "forest", "It's so thick that it's completely impenetrable",
  });

  ::reset(arg);
  replace_program("room/room");
}

