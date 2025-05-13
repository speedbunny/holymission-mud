#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object sal;

reset(arg) {
  if(!sal) MOVE(sal = CLONE(NWDESERT + "monsters/salamander"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste06", "north",
    NWDESERT + "rooms/shadow04", "northwest",
    NWDESERT + "rooms/shadow02", "northeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west, east and south",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "east");
  add_action("no_way", "south");
}

