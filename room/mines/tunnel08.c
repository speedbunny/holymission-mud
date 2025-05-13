inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Shaft";
  long_desc =
    "This shaft leads down into the mine tunnels further under the "+
    "mountain. It also leads up and out to ground level.\n";

  items = ({
    "shaft", "A tunnel leading up and down to different levels of the "+
      "mine",
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel03", "up",
    MINES + "tunnel09", "down",
  });

  ::reset(arg);
  replace_program("room/room");
}
