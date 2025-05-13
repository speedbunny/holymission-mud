inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Newbie Training Area";
    long_desc="There are even more training rooms to\n" +
              "the east and the west here.  And there \n" +
              "is also one to the north.\n";

    dest_dir=({TRAIN + "1_11","west",
               TRAIN + "1_14","north",
               TRAIN + "1_13","east",
               TRAIN + "1_9","south",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
