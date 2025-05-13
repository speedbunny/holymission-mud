inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Newbie Training Area";
    long_desc="There are more training rooms to the\n" +
              "east and the west.\n";

    dest_dir=({TRAIN + "1_12","north",
               TRAIN + "1_10","east",
               TRAIN + "1_6","south",
               TRAIN + "1_8","west",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
