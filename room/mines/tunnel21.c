inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "A tunnel in the mines.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel22", "east",
    MINES + "tunnel20", "west",
  });

  ::reset(arg);
  replace_program("room/room");
}
