inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Dark Forest";
  long_desc =
    "    The forest is dark here. You can catch a brief glimpse of\n" +
    "the sun's rays through a few cracks in the canopy of branches\n" +
    "hanging over your head, but besides this no other light can\n" +
    "be seen. There is no path here, but in some directions the\n" +
    "trees are sparse enough to allow you to pass.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a06", "south",
    NWFORESTA + "rooms/a10", "northwest",
    NWFORESTA + "rooms/a02", "northeast",
  });

  items = ({
    "forest", "You stand within the Western Forest",
    "branches", "Thick, wasted branches over your head",
    "canopy", "A thick mass of branches above you",
    "trees", "Densely packed trees",
  });
  replace_program("/room/room");
}
