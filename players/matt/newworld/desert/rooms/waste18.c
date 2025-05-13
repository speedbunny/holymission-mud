#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/shadow11", "west",
    NWDESERT + "rooms/waste12", "east",
    NWDESERT + "rooms/shadow12", "north",
    NWDESERT + "rooms/waste17", "south",
    NWDESERT + "rooms/waste13", "northeast",
    NWDESERT + "rooms/shadow10", "southwest",
    NWDESERT + "rooms/waste11", "southeast",
  });
  clone_list = ({
    1, 1, "scorpion", NWDESERT + "monsters/pscorpion", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
