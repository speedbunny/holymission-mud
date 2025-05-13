inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "In a tunnel in the mines.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel15", "east",
    MINES + "tunnel09", "west",
  });

  ::reset(arg);
  replace_program("/room/room");
}
