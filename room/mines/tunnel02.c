inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "In the tunnel into the mines.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel03", "north",
    MINES + "tunnel01", "southeast",
  });

  ::reset(arg);
  replace_program("/room/room");
}

