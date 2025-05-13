inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  no_castle_flag = 1;
   
  set_light(1);      
  short_desc = "Jetty";

  long_desc =
    "You are at a jetty. The waves roll in from east. " +
    "A small path leads back to west.\n";
               
  dest_dir = ({
    EAST + "sea", "east",
    EAST + "shoreroad29", "west",
  });

  clone_list = ({
    1, 1, "bag", "obj/bag", 0,
  });

  ::reset(arg);
  replace_program("room/room");
}

