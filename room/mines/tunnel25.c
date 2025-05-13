inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "The tunnel slopes steeply uphill, ending in a hole leading up to the "+
    "next level.  To the north, the tunnel continues on a level surface.\n";

  items = ({
    "tunnel", "It is dark",
    "hole","The tunnel slopes up to a large hole leading to an upper level",
  });

  dest_dir = ({
    MINES + "tunnel26", "north",
    MINES + "tunnel24", "up",
  });

  ::reset(arg);
  replace_program("/room/room");
}
