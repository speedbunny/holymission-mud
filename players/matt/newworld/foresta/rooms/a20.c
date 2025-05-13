inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(-1);
  short_desc = "Deep Forest";
  long_desc =
    "    An unnatural darkness hangs over this section of the\n" +
    "forest, a palpable gloom that weighs heavily upon your\n" +
    "shoulders. You sense evil here, and with it a deep cold\n" +
    "that chills you through your flesh into your spirit.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a17", "east",
    NWFORESTA + "rooms/a21", "south",
  });

  items = ({
    "forest", "It is unnaturally dark",
  });
  replace_program("/room/room");
}
