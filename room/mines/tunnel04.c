inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "In the tunnel in the mines under the mountain.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel05", "north",
    MINES + "tunnel03" ,"south",
  });

  ::reset(arg);
  replace_program("room/room");
}
