#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow13", "west",
    NWDESERT + "rooms/waste14", "east",
    NWDESERT + "rooms/shadow12", "south",
    NWDESERT + "rooms/shadow15", "northeast",
    NWDESERT + "rooms/waste13", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the north",
  });
}

init() {
  ::init();
  add_action("no_way", "north");
}

