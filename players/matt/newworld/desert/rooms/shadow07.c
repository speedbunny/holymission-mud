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
    NWDESERT + "rooms/waste09", "east",
    NWDESERT + "rooms/waste16", "north",
    NWDESERT + "rooms/shadow06", "south",
    NWDESERT + "rooms/shadow08", "northwest",
    NWDESERT + "rooms/waste10", "northeast",
    NWDESERT + "rooms/waste08", "southeast",
  });

  items = ({
    "cliffs", "High, sheer cliffs to the west",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
}

