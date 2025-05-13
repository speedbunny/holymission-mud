#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/shadow08", "west",
    NWDESERT + "rooms/waste10", "east",
    NWDESERT + "rooms/waste17", "north",
    NWDESERT + "rooms/shadow07", "south",
    NWDESERT + "rooms/shadow10", "northwest",
    NWDESERT + "rooms/waste11", "northeast",
    NWDESERT + "rooms/waste09", "southeast",
  });
  clone_list = ({
    1, 2, "vulture", NWDESERT + "monsters/vulture", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
