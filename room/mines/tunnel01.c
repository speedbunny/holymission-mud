inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Mine entrance";
  long_desc =
    "The dark tunnel heads further into the bowels of the "+
    "mountain.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel02", "northwest",
    MINES + "entrance", "southeast",
  });

  ::reset(arg);
  replace_program("/room/room");
}                       
