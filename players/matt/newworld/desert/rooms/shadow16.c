#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow15", "south",
    NWDESERT + "rooms/shadow17", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west, east, and north",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "east");
  add_action("no_way", "north");
}

