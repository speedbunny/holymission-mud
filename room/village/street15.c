inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "South Main Street";
  long_desc =
    "Main street continues north-east here. The street is surrounded "+
    "by buildings that are boarded up, preventing any admittance. "+
    "Perhaps once this used to be a more homely part of town.\n";

  dest_dir = ({
    HM_VILLAGE + "street14", "north",
    HM_VILLAGE + "street16", "east",
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "buildings","You see no visible entrances into the buildings",
    "entrance","There are none visible",
  });

  ::reset(arg);
  replace_program("room/room");
}

