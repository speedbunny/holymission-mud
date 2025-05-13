#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object scorp;

reset(arg) {
  if(!scorp) MOVE(scorp = CLONE(NWDESERT + "monsters/gscorpion"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste18", "east",
    NWDESERT + "rooms/shadow10", "south",
    NWDESERT + "rooms/shadow12", "northeast",
    NWDESERT + "rooms/waste17", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west and north",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "north");
}

