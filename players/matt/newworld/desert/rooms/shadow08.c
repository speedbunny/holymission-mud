#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object jackal1;
object jackal2;

reset(arg) {
  if(!jackal1) MOVE(jackal1 = CLONE(NWDESERT + "monsters/jackal"), TO);
  if(!jackal2) MOVE(jackal2 = CLONE(NWDESERT + "monsters/jackal"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow09", "west",
    NWDESERT + "rooms/waste16", "east",
    NWDESERT + "rooms/shadow10", "north",
    NWDESERT + "rooms/waste17", "northeast",
    NWDESERT + "rooms/shadow07", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the south",
  });
}

init() {
  ::init();
  add_action("no_way", "south");
}

