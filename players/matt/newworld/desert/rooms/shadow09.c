#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object coyote;

reset(arg) {
  if(!coyote) MOVE(coyote = CLONE(NWDESERT + "monsters/coyote"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow08", "east",
    NWDESERT + "rooms/shadow10", "northeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west, north, and south",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "north");
  add_action("no_way", "south");
}

