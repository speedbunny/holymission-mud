inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc="The northern part of Rich Men's Road";
  long_desc=
    "You stand on the northern part of Rich Men's Road. "+
    "Further to the north you see the northern gate out of "+
    "the village. West stands a stone building waiting for a "+
    "wizard to make it into something.\n";

  dest_dir=({
    HM_VILLAGE + "road6", "north",
    HM_VILLAGE + "road4", "south",
  });

  items=({
    "rich men's road","The brick road through the richer part of "+
      "the village",
    "road","A paved road, made of red bricks",
    "bricks","Red bricks form the roadsurface",
    "gate","A strong wooden gate in the stockade that surrounds the "+
      "village",
    "stockade","A wooden defense wall, made of sharply pointed poles",
  });

  ::reset(arg);
  replace_program("room/room");
}

