#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow15", "west",
    NWDESERT + "rooms/shadow18", "south",
    NWDESERT + "rooms/shadow16", "northwest",
    NWDESERT + "rooms/waste14", "southwest",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the east and north",
  });
}

init() {
  ::init();
  add_action("no_way", "east");
  add_action("no_way", "north");
}

