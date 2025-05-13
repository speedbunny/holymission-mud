inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Galleria Hallway";
    long_desc="This is a brightly lit hallway in the famous Willieo's\n" +
              "Galleria.  There are rooms along the whole length of the\n" +
              "hallway.  Maybe you should go into a few or all of them?\n";

    dest_dir=({GALL + "upper_hall","south",
               GALL + "wiz1","west",
               GALL + "hallway1_2","north",
    });
    items=({"hallway","It is a very nice looking hallway",
            "rooms","Try out a few of them.  You might like them",
    });
    set_light(1);
return 1;
  }
}
