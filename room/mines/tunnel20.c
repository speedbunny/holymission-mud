inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel dead-end";
  long_desc = 
    "The tunnel has dead-ended where the miners apparently quit mining.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel21", "east",
  });

  ::reset(arg);
  replace_program("/room/room");
}
