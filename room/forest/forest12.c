inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Deep forest";

  long_desc =
    "You are in the deep forest.\n";

  items = ({
    "forest", "You are in the heart of it",
  });

  smell = "You smell the fresh air of the forest.";

  dest_dir = ({
    FOREST + "forest11", "east",
    FOREST + "forest13", "west",
//    "/players/meecham/tower/entrance", "west",
//    SOUTH + "sforst1", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}
