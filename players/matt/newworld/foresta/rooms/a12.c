inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    For some reason a strong wind blows through here, causing\n" +
    "the tree branches to sway and move with their own life. Gusts\n" +
    "find their way through tiny cracks and crevices in the trees,\n" +
    "making a high-pitched whistling sound at irregular intervals.\n" +
    "The wind almost sounds as though it is trying to speak.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a09", "east",
    NWFORESTA + "rooms/a16", "northwest",
    NWFORESTA + "rooms/a17", "southwest",
  });

  items = ({
    "trees", "The trees bend and sway, animated by the wind",
    "branches", "The thinner branches whip about in the wind",
    "cracks", "Small worm-eaten holes bored into the trees",
    "crevices", "Narrow spaces between branches",
  });
  replace_program("/room/room");
}
