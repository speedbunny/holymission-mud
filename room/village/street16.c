inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "South Main Street";
  long_desc =
    "Main street continues west-south here. The sides of the street "+
    "are blocked by buildings which have been boarded up. This looks "+
    "to be a darker side of town.\n";

  dest_dir = ({
    HM_VILLAGE + "street15", "west",
    HM_VILLAGE + "street17", "south",
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "buildings","You see no visible entrances into the buildings",
    "entrance","There are none",
  });

  ::reset(arg);
  replace_program("room/room");
}

