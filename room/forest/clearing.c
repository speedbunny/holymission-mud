inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Clearing";

  long_desc = 
    "This small clearing in the middle of the forest seems "+
    "to provide a nice haven for the weak and weary. "+
    "Trees surround you on all sides except the north, where "+
    "they appear sparse.\n";

  smell = "You smell the fresh air of the forest.";

  items = ({
    "clearing", "It is open and covered with grass",
    "trees", "They look healthy and big",
  });

  dest_dir = ({
    PLAIN + "plain01", "north",
    FOREST + "forest01", "east",
    FOREST + "forest02", "west",
  });

  ::reset(arg);
  replace_program("room/room");
}
