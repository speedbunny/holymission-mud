inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "The tunnel splits into a fork to the north.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel22", "north",
    MINES + "tunnel17", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}
