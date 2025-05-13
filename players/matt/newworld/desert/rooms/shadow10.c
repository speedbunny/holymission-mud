#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste17", "east",
    NWDESERT + "rooms/shadow11", "north",
    NWDESERT + "rooms/shadow08", "south",
    NWDESERT + "rooms/waste18", "northeast",
    NWDESERT + "rooms/shadow09", "southwest",
    NWDESERT + "rooms/waste16", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
}

