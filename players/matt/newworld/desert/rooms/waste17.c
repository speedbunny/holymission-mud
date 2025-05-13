#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/shadow10", "west",
    NWDESERT + "rooms/waste11", "east",
    NWDESERT + "rooms/waste18", "north",
    NWDESERT + "rooms/waste16", "south",
    NWDESERT + "rooms/shadow11", "northwest",
    NWDESERT + "rooms/waste12", "northeast",
    NWDESERT + "rooms/shadow08", "southwest",
    NWDESERT + "rooms/waste10", "southeast",
  });
  clone_list = ({
    1, 1, "scorpion", NWDESERT + "monsters/scorpion", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
