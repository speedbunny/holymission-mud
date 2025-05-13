inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "The mine tunnel continues both east and west here.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel09", "east",
    MINES + "tunnel11", "west",
  });

  ::reset(arg);
  replace_program("/room/room");
}
