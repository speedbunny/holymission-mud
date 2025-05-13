inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Newbie Training Area";
    long_desc="There are training rooms to the east\n" +
              "and the west.\n";

    dest_dir=({TRAIN + "1_3","south",
               TRAIN + "1_9","north",
               TRAIN + "1_5","west",
               TRAIN + "1_7","east",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
