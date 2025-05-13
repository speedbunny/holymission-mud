#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/waste16", "west",
    NWDESERT + "rooms/waste03", "east",
    NWDESERT + "rooms/waste11", "north",
    NWDESERT + "rooms/waste09", "south",
    NWDESERT + "rooms/waste17", "northwest",
    NWDESERT + "rooms/waste04", "northeast",
    NWDESERT + "rooms/shadow07", "southwest",
    NWDESERT + "rooms/waste02", "southeast",
  });
  clone_list = ({
    1, 2, "buzzard", NWDESERT + "monsters/buzzard", 0,
    2, 2, "vulture", NWDESERT + "monsters/vulture", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
