inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "The tunnel slopes steeply down a hole here. Luckily, this hole "+
    "is not as steep as the one used to gain entrance to the mines.\n";

  items = ({
    "tunnel", "It is dark",
    "hole", "A sloping hole one can walk on foot down",
  });

  dest_dir = ({
    MINES + "tunnel23", "west",
    MINES + "tunnel25", "down",
  });

  ::reset(arg);
  replace_program("/room/room");
}
