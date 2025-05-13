inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Deep forest";

  long_desc =
    "You are in the deep forest. Trees surround you making travel "+
    "somewhat difficult, but as you are looking for the best way "+
    "out, you spy a path behind some trees, leading north.\n";

  items = ({
    "forest", "It is filled with trees",
    "trees", "There are a lot",
    "path", "It leads north",
  });

  smell = "You smell the fresh air of the forest.";

  dest_dir = ({
    "/players/figleaf/smurf/path","north",
    FOREST + "forest05", "east",
    FOREST + "forest20", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}
