#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow17", "east",
    NWDESERT + "rooms/shadow16", "north",
    NWDESERT + "rooms/waste14", "south",
    NWDESERT + "rooms/shadow14", "southwest",
    NWDESERT + "rooms/shadow18", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
}

