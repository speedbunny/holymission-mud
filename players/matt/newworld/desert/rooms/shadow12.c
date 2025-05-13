#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste13", "east",
    NWDESERT + "rooms/shadow14", "north",
    NWDESERT + "rooms/waste18", "south",
    NWDESERT + "rooms/shadow13", "northwest",
    NWDESERT + "rooms/waste14", "northeast",
    NWDESERT + "rooms/shadow11", "southwest",
    NWDESERT + "rooms/waste12", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
}

