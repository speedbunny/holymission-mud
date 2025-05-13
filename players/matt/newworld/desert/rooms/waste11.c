#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/waste17", "west",
    NWDESERT + "rooms/waste04", "east",
    NWDESERT + "rooms/waste12", "north",
    NWDESERT + "rooms/waste10", "south",
    NWDESERT + "rooms/waste18", "northwest",
    NWDESERT + "rooms/waste05", "northeast",
    NWDESERT + "rooms/waste16", "southwest",
    NWDESERT + "rooms/waste03", "southeast",
  });
  clone_list = ({
    1, 2, "buzzard", NWDESERT + "monsters/buzzard", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
