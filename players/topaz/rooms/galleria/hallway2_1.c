inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Galleria Hallway";
    long_desc="You are in a hallway of Willieo's Galleria.\n" +
              "There are game rooms all along this hallway.\n";

    dest_dir=({GALL + "upper_hall.c","west",
               GALL + "pinballroom","north",
    });
    items=({"hallway","A nice, clean hallway",
            "hall","A nice, clean hallway",
            "rooms","Try going in one of them",
            "game rooms","Try going in one of them",
    });
    set_light(1);
return 1;
  }
}
