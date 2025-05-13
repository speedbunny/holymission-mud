#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;

  dest_dir = ({
    NWDESERT + "rooms/waste18", "west",
    NWDESERT + "rooms/waste05", "east",
    NWDESERT + "rooms/waste13", "north",
    NWDESERT + "rooms/waste11", "south",
    NWDESERT + "rooms/shadow12", "northwest",
    NWDESERT + "rooms/shadow19", "northeast",
    NWDESERT + "rooms/waste17", "southwest",
    NWDESERT + "rooms/waste04", "southeast",
  });
  clone_list = ({
    1, 1, "scorpion", NWDESERT + "monsters/scorpion", 0,
  });
  ::reset(arg);
  replace_program("room/room");
}
