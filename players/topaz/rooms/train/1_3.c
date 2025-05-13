inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Newbie Training Area";
    long_desc="There are training rooms to the east\n" +
              "and the west.\n";

    dest_dir=({TRAIN + "1_1","south",
               TRAIN + "1_6","north",
               TRAIN + "1_2","west",
               TRAIN + "1_4","east",
    });
    items=({"rooms","Check them out!  Maybe there's something to kill in there",
    });
    set_light(1);
return 1;
  }
}
