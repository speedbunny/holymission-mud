#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/shadow04", "west",
    NWDESERT + "rooms/shadow02", "east",
    NWDESERT + "rooms/waste07", "north",
    NWDESERT + "rooms/shadow03", "south",
    NWDESERT + "rooms/waste15", "northwest",
    NWDESERT + "rooms/shadow01", "northeast",
  });
  clone_list = ({
    1, 1, "toad", NWDESERT + "monsters/gianttoad", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
