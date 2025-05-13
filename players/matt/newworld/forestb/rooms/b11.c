inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    This is what feels like the center of the forest. You sense\n" +
    "that you are deep inside now, surrounded on all sides by mighty\n" +
    "trees and the tranquility that only nature can provide. Several\n" +
    "paths lead away from here, if they can be called such.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b14", "east",
    NWFORESTB + "rooms/b10", "north",
    NWFORESTB + "rooms/b12", "south",
    NWFORESTB + "rooms/b13", "northeast",
  });

  items = ({
    "forest", "The central area of this forest",
    "trees", "Tall trees",
    "paths", "Rough, crude paths cleared through the foliage",
  });
  replace_program("/room/room");
}
