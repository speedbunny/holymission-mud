inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The intersection of Main and West Street";
  long_desc =
    "You've arrived at the intersection of Main Street and West Street. "+
    "Main street leads north and south and West Street heads west, toward "+
    "the city gate.  Several buildings line West Street.  To the east "+
    "rises the wall of the village church.\n";

  dest_dir = ({
    HM_VILLAGE + "street06", "north",
    HM_VILLAGE + "street08", "west",
    HM_VILLAGE + "street13", "south",
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "west street","There are a few buildings along the street",
    "intersection","The intersection of Main and West streets",
    "corner","Just another turn in the road",
    "buildings","Go there if you want to find out what they are",
    "wall","The curved wall surrounds the altar that stands within"
  });

  ::reset(arg);
  replace_program("room/room");
}

