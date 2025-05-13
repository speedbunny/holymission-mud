inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The western corner of Rich Men's Road";
  long_desc =
    "You've arrived at the western corner of Rich Men's Road. "+
    "From here the road leads north and east. To the south "+
    "stands a stone house empty, waiting for a wizard to open "+
    "a shop there.\n";

  dest_dir = ({
    HM_VILLAGE + "road5", "north",
    HM_VILLAGE + "road3", "east",
  });

  items = ({
    "corner","From here the red brick road leads north and east",
    "rich men's road","The road leading through the richer part of "+
      "the village",
    "road","A well paved road, made of red bricks",
    "bricks","It looks like the red brick roadsurface is cleaned "+
      "quite often",
    "house","A house, built of yellow bricks",
  });

  ::reset(arg);
  replace_program("room/room");
}

