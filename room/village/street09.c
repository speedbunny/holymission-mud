inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "South of the village shop";
  long_desc =
    "North from this point of West Street lies the door to the famous "+
    "'Tools & Things' shop. Main Street continues both to the east "+
    "and to the west.\n";

  dest_dir = ({
    HM_VILLAGE + "shop", "north",
    HM_VILLAGE + "street08", "east",
    HM_VILLAGE + "street10", "west",
  });

  items = ({
    "west street","The road leading to the western gate of the village",
    "street","The major road through the village",
    "road","A well maintained dirt road",
    "shop","The general shop that serves this village",
  });

  ::reset(arg);
  replace_program("room/room");
}

