#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/waste15", "west",
    NWDESERT + "rooms/shadow01", "east",
    NWDESERT + "rooms/waste08", "north",
    NWDESERT + "rooms/waste06", "south",
    NWDESERT + "rooms/shadow06", "northwest",
    NWDESERT + "rooms/waste01", "northeast",
    NWDESERT + "rooms/shadow04", "southwest",
    NWDESERT + "rooms/shadow02", "southeast",
  });
  replace_program("/room/room");
}
