inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The western part of Main Street";
  long_desc =
    "You are travelling along the western portion of West Street.  The "+
    "gate leading to the outside world and all its perils lies just to "+
    "the west.  West Street continues to the east.\n";

  dest_dir = ({
    HM_VILLAGE + "street09", "east",
    HM_VILLAGE + "street11", "west",
  });

  items = ({
    "west street","The road ends just to the west of here",
    "street","The major road through the village ends just west from here",
    "gate","The gate in the stockade forms the western exit from the "+
      "village",
    "stockade","A wooden defense wall, made of sharply pointed poles",
    "village","A simple woodsmen's village",
  });

  ::reset(arg);
  replace_program("room/room");
}

