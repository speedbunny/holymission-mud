inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "City Road";
  long_desc =
    "    You are on the road to Dyolf City, which runs northwest\n" +
    "and southeast here. The path slopes upward to the north and\n" +
    "downward to the south, and on either side the land is rough\n" +
    "and rocky. You are fairly high in the hills now.\n";

  dest_dir = ({
    NWROAD + "rooms/road13", "northwest",
    NWROAD + "rooms/road11", "southeast",
  });

  items = ({
    "road", "This is a well-used path into the city",
  });
  replace_program("/room/room");
}
