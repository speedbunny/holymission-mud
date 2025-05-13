#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste14", "west",
    NWDESERT + "rooms/shadow17", "north",
    NWDESERT + "rooms/shadow19", "south",
    NWDESERT + "rooms/shadow15", "northwest",
    NWDESERT + "rooms/waste13", "southwest",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the east",
  });
}

init() {
  ::init();
  add_action("no_way", "east");
}

