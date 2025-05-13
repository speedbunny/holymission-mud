#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste15", "east",
    NWDESERT + "rooms/shadow06", "northeast",
    NWDESERT + "rooms/shadow04", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west, north, and south",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "north");
  add_action("no_way", "south");
}

