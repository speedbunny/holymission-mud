inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Heart of the Forest";
  long_desc =
    "    This is the heart of the forest. The trees are somewhat\n" +
    "sparse here, but still no light can penetrate the branches\n" +
    "overhead. You have no sense of time at all in this place.\n" +
    "    To the west the forest seems to become darker.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a20", "west",
    NWFORESTA + "rooms/a13", "east",
    NWFORESTA + "rooms/a18", "south",
    NWFORESTA + "rooms/a12", "northeast",
  });

  items = ({
    "trees", "Loosely-packed black trees",
    "forest", "You suspect that this is the center of the forest",
    "branches", "Dark branches silently lurking above you",
  });
  replace_program("/room/room");
}
