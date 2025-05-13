inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "South Main Street";
  long_desc =
    "Main street continues north-south here. To the south the street "+
    "ends at the town wall. The buildings provide no visible entrances "+
    "either. This part of town definitely looks to be dead.\n";

  dest_dir = ({
    HM_VILLAGE + "street16", "north",
    HM_VILLAGE + "street18", "south",
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "wall","The town wall is to the south",
    "buildings","You see no visible entrances into the buildings",
    "entrance","There are none",
  });

  ::reset(arg);
  replace_program("room/room");
}

