#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste13", "west",
    NWDESERT + "rooms/shadow18", "north",
    NWDESERT + "rooms/waste05", "south",
    NWDESERT + "rooms/waste14", "northwest",
    NWDESERT + "rooms/waste12", "southwest",
    NWDESERT + "rooms/desert05", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the east",
  });
}

init() {
  ::init();
  add_action("no_way", "east");
}

