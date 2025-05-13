#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object lizard1;
object lizard2;

reset(arg) {
  if(!lizard1) MOVE(lizard1 = CLONE(NWDESERT + "monsters/greenlizard"), TO);
  if(!lizard2) MOVE(lizard2 = CLONE(NWDESERT + "monsters/greenlizard"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste07", "west",
    NWDESERT + "rooms/waste01", "north",
    NWDESERT + "rooms/shadow02", "south",
    NWDESERT + "rooms/waste08", "northwest",
    NWDESERT + "rooms/desert02", "northeast",
    NWDESERT + "rooms/waste06", "southwest",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the east",
  });
}
     
init() {
  ::init();
  add_action("no_way", "east");
}
