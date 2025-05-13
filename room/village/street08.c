inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Southern Main Street";
  long_desc =
    "West Steet runs east and west, leading from Main Street to the "+
    "western gate of the village.  The blind wall of a building decorates "+
    "the north side of the road.\n";

  dest_dir = ({
    HM_VILLAGE + "street07", "east",
    HM_VILLAGE + "street09", "west", 
  });

  items = ({
    "main street","The major road through the village",
    "west street","This small street leads to the outside world",
    "street","The major road through the village",
    "road","A well maintained dirt road",
    "gate","A gate in the stockade that surrounds the village leads outside",
    "stockade","A wooden wall of pointed poles serves to keep any "+
      "dangers out of the village",
    "wall","The southern wall of a building",
    "building","A shop of some kind. It has its entrance east from here",
  });

  ::reset(arg);
  replace_program("room/room");
}

