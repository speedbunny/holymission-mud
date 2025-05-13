inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Shore road";

  long_desc =
    "Shore road runs east-west here and appears to lead to the "+
    "coast to the east. In fact, you can barely make out the sound "+
    "of waves in the distance.\n";

  dest_dir = ({
    EAST + "shoreroad29", "east",
    EAST + "shoreroad27", "west",
  });

  items = ({
    "road", "The road continues both east and west",
    "coast", "You do not see any coastline"
  });

  replace_program("room/room");
}
