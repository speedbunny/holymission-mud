#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste09", "west",
    NWDESERT + "rooms/desert03", "east",
    NWDESERT + "rooms/waste03", "north",
    NWDESERT + "rooms/waste01", "south",
    NWDESERT + "rooms/waste10", "northwest",
    NWDESERT + "rooms/waste08", "southwest",
    NWDESERT + "rooms/desert02", "southeast",
  });
  replace_program("/room/room");
}
