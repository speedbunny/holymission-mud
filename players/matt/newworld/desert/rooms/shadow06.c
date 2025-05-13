#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/shadow";

object *hyenas = ({ 0, 0, 0, 0, 0 });

reset(arg) {
  int i;
  for(i = 0; i < 5; i++)
    if(!hyenas[i]) MOVE(hyenas[i] = CLONE(NWDESERT + "monsters/hyena"), TO);
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste08", "east",
    NWDESERT + "rooms/shadow07", "north",
    NWDESERT + "rooms/waste15", "south",
    NWDESERT + "rooms/waste09", "northeast",
    NWDESERT + "rooms/shadow05", "southwest",
    NWDESERT + "rooms/waste07", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
}

