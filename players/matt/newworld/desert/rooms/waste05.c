#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/waste12", "west",
    NWDESERT + "rooms/desert05", "east",
    NWDESERT + "rooms/shadow19", "north",
    NWDESERT + "rooms/waste04", "south",
    NWDESERT + "rooms/waste13", "northwest",
    NWDESERT + "rooms/waste11", "southwest",
    NWDESERT + "rooms/desert04", "southeast",
  });
  clone_list = ({
    1, 1, "cobra", NWDESERT + "monsters/cobra", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
