#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow05", "west",
    NWDESERT + "rooms/waste07", "east",
    NWDESERT + "rooms/shadow06", "north",
    NWDESERT + "rooms/shadow04", "south",
    NWDESERT + "rooms/waste08", "northeast",
    NWDESERT + "rooms/waste06", "southeast",
  });
  replace_program("/room/room");
}
