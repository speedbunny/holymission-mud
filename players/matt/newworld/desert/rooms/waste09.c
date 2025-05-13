#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/shadow07", "west",
    NWDESERT + "rooms/waste02", "east",
    NWDESERT + "rooms/waste10", "north",
    NWDESERT + "rooms/waste08", "south",
    NWDESERT + "rooms/waste16", "northwest",
    NWDESERT + "rooms/waste03", "northeast",
    NWDESERT + "rooms/shadow06", "southwest",
    NWDESERT + "rooms/waste01", "southeast",
  });
  clone_list = ({
    1, 2, "buzzard", NWDESERT + "monsters/buzzard", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
