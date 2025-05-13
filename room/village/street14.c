inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "South Main Street";
  long_desc =
    "Main street continues north-south here. On both sides of the "+
    "street, the buildings have been boarded up preventing any "+
    "visible entrance.\n";

  dest_dir = ({
    HM_VILLAGE + "street13", "north",
    HM_VILLAGE + "street15", "south",
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "buildings","You see no visible entrance into the building",
    "entrance","There are no entrances that you can see",
  });

  ::reset(arg);
  replace_program("room/room");
}

