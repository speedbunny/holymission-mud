inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Shore road";

  long_desc =
    "Shore road runs east-west here and appears to lead to the "+
    "coast to the east.\n";

  dest_dir = ({
    EAST + "shoreroad27", "east",
    EAST + "shoreroad25", "west",
  });

  items = ({
    "road", "The road continues both east and west",
    "coast", "You do not see any coastline"
  });

  replace_program("room/room");
}
