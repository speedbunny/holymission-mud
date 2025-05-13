inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Deep forest";

  long_desc =
    "You are in a forest. The path leads east and " +
    "south from here.\n";

  items = ({
    "forest", "Everything looks dark green",
    "path", "It is a path through the forest",
  });

  smell = "You smell the fresh air of the forest.";

  dest_dir = ({
    FOREST + "forest02", "east",
    FOREST + "forest11", "west",
    FOREST + "forest03", "south",
  });

  "players/cashimor/objects/sandmass"->short();
  ::reset(arg);
  replace_program("room/room");
}

