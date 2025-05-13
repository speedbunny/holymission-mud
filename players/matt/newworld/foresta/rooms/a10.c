inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    You are on a winding path, to use the term loosely,\n" +
    "through the forest. The path is more of a series of breaks\n" +
    "in the density of the trees, which allows you to progress\n" +
    "further. It is very dark here, but you can make out breaks\n" +
    "to the southwest and southeast.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a14", "southwest",
    NWFORESTA + "rooms/a05", "southeast",
  });

  items = ({
    "path", "Not really a path per se",
    "forest", "You stand in the Western Forest",
    "breaks", "Narrow openings amidst the multitude of trees",
    "trees", "Densely packed trees",
  });
  replace_program("/room/room");
}
