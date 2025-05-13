#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste11", "west",
    NWDESERT + "rooms/desert04", "east",
    NWDESERT + "rooms/waste05", "north",
    NWDESERT + "rooms/waste03", "south",
    NWDESERT + "rooms/waste12", "northwest",
    NWDESERT + "rooms/desert05", "northeast",
    NWDESERT + "rooms/waste10", "southwest",
  });
  replace_program("/room/room");
}
