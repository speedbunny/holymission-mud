inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dead End";
  long_desc =
    "    A dense crowd of trees stands before you, blocking any\n" +
    "further movement. The only way out is to the west.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a17", "west",
  });

  items = ({
    "trees", "Thick-trunked black trees blocking forward movement",
  });
  replace_program("/room/room");
}
