inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Fork in the tunnel";
  long_desc =
    "The tunnel forks here leaving three directions with which to "+
    "pursue.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel23", "east",
    MINES + "tunnel21", "west",
    MINES + "tunnel19", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}
