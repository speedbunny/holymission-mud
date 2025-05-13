inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "A large open plain stretches northward and eastward from "+
    "here. The forest to the south and west blocks travel in "+
    "those directions.\n";

  items = ({
    "plain", "It is a wide plain with grass blowing in the wind",
    "grass", "It looks more like grain from here",
    "forest", "It is too thick to enter here",
  });

  dest_dir = ({
    PLAIN + "plain07", "north",
    PLAIN + "plain02", "east",
  });

  ::reset(arg);
  replace_program("/room/room");
}

