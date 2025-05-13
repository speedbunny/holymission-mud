inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    Here the path leads south, into a rather large clearing,\n" +
    "and northwest, deeper into the woods. You also notice a small\n" +
    "break in the trees to the northeast, not part of the path but\n" +
    "still wide enough to allow passage. The air is clear and warm,\n" +
    "and the glimmers of sunlight bathe you in their lazy beams.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b19", "south",
    NWFORESTB + "rooms/b16", "northwest",
    NWFORESTB + "rooms/b21", "northeast",
  });

  items = ({
    "clearing", "A large clearing to the south",
    "trees", "Mighty trees withstanding the ages",
    "break", "A break in the densely-packed trees to the northwest",
    "path", "An old, overgrown path which you now stand on",
    "sunlight", "The sunlight makes its way down here through the trees",
    "beams", "Beams of sunlight",
  });
  replace_program("/room/room");
}
