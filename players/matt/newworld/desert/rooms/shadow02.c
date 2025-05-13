#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object lizard;

reset(arg) {
  if(!lizard) MOVE(lizard = CLONE(NWDESERT + "monsters/brownlizard"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste06", "west",
    NWDESERT + "rooms/shadow01", "north",
    NWDESERT + "rooms/waste07", "northwest",
    NWDESERT + "rooms/shadow03", "southwest",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the east and south",
  });
}

init() {
  ::init();
  add_action("no_way", "east");
  add_action("no_way", "south");
}
