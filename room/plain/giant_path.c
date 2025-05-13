inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc="A path";

  long_desc=
    "You are on a path going in an east-west direction through "+
    "the plains.  There are some VERY big footprints here.  There "+
    "is a tree to the east.\n";

  items = ({
    "path", "The path goes to the east and west",
    "plains", "They go east and west",
    "footprints","They are very big and humanoid shaped",
    "tree", "It is to the east",
  });

  dest_dir=({
    PLAIN + "big_tree", "east",
    PLAIN + "giant_lair", "west",
  });

  ::reset(arg);
  replace_program("room/room");
}
