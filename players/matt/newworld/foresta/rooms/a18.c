inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    You are deep within the Western Forest. Here the trees\n" +
    "seem even more thickly packed, darker, more forbidding. The\n" +
    "sounds of the forest echo oddly back to your ears, making\n" +
    "them sound foreign and unnatural.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a17", "north",
    NWFORESTA + "rooms/a19", "south",
  });

  items = ({
    "trees", "Gnarled old trees reaching for you with arm-like branches",
    "forest", "This seems to be close to the center of the forest",
  });
  replace_program("/room/room");
}
