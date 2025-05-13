#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste06", "east",
    NWDESERT + "rooms/waste15", "north",
    NWDESERT + "rooms/shadow05", "northwest",
    NWDESERT + "rooms/waste07", "northeast",
    NWDESERT + "rooms/shadow03", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west and south",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "south");
}

