inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "The tunnel continues to lead north. Someone appears to have left "+
    "a heavy stone table here in the room.\n";

  items = ({
    "table", "It is much too heavy to lift",
    "stone table", "It is much too heavy to lift",
    "tunnel", "It is dark",
  }); 

  dest_dir = ({
    MINES + "tunnel_room", "north",
    MINES + "tunnel04", "south",
  }); 

  ::reset(arg);
  replace_program("/room/room");
}
