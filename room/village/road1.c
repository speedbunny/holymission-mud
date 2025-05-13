inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The beginning of Rich Men's Road";

  long_desc =
    "At this place Rich Men's road begins. It's still a dirt "+
    "road here, but it gets better further north, where it leads "+
    "into the richer part of the village. An intersection of "+
    "roads lies south.\n";

  dest_dir = ({
    HM_VILLAGE + "road2", "north",
    HM_VILLAGE + "street04", "south",
  });

  items = ({
    "rich men's road","This road leads into the richer part of the "+
      "village and is paved further on",
    "road","It's a dirt road here, but it becomes a paved road north "+
      "of here",
    "intersection","An intersection of roads in the centre of the village",
  });

  ::reset(arg);
  replace_program("room/room");
}

