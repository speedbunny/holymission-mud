inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
   "The tunnel splits leaving directions leading north, south and east.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel27", "north",
    MINES + "tunnel28", "east",
    MINES + "tunnel25", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}
