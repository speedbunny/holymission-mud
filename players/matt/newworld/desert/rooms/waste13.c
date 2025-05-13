#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow12", "west",
    NWDESERT + "rooms/shadow19", "east",
    NWDESERT + "rooms/waste14", "north",
    NWDESERT + "rooms/waste12", "south",
    NWDESERT + "rooms/shadow14", "northwest",
    NWDESERT + "rooms/shadow18", "northeast",
    NWDESERT + "rooms/waste18", "southwest",
    NWDESERT + "rooms/waste05", "southeast",
  });
  replace_program("/room/room");
}
