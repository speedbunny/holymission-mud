inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Dead end";
  long_desc =
    "The tunnel has dead-ended here.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel17", "east",
  });

  ::reset(arg);
  replace_program("room/room");
}
