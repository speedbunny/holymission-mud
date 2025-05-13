inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "South Main Street";
  long_desc =
    "Main street continues north-south here. To the east is the "+
    "entrance to the newbie guild, where those who are new can "+
    "learn and improve. The other side of the street has a "+
    "boarded up building.\n";

  dest_dir = ({
    HM_VILLAGE + "street07", "north",
    HM_VILLAGE + "street14", "south",
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "building","You see no visible entrance into the building",
    "guild","The newbie guild is for new players and is highly "+
      "protected",
    "entrance","The newbie guild is for new players and is highly "+
      "protected",
  });

  ::reset(arg);
  replace_program("room/room");
}

