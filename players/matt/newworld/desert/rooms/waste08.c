#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow06", "west",
    NWDESERT + "rooms/waste01", "east",
    NWDESERT + "rooms/waste09", "north",
    NWDESERT + "rooms/waste07", "south",
    NWDESERT + "rooms/shadow07", "northwest",
    NWDESERT + "rooms/waste02", "northeast",
    NWDESERT + "rooms/waste15", "southwest",
    NWDESERT + "rooms/shadow01", "southeast",
  });
  replace_program("/room/room");
}
