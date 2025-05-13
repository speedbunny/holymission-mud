#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/waste10", "west",
    NWDESERT + "rooms/scrub03", "east",
    NWDESERT + "rooms/waste04", "north",
    NWDESERT + "rooms/waste02", "south",
    NWDESERT + "rooms/waste11", "northwest",
    NWDESERT + "rooms/desert04", "northeast",
    NWDESERT + "rooms/waste09", "southwest",
    NWDESERT + "rooms/desert03", "southeast",
  });
  clone_list = ({
    1, 2, "vulture", NWDESERT + "monsters/vulture", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
