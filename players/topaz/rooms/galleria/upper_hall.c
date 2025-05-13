inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Galleria Upstairs";
    long_desc="This grand hall is breathtaking!  You are amazed\n" +
              "at how beatiful it is here.  You hear the sounds of people\n" +
              "having fun all around you.\n" +
              "There are hallways leading off in several directions, and\n" +
              "you see a few rooms.  Please feel free to explore this\n" +
              "wonderful place!  The main stairs lead down from here.\n";

    dest_dir=({GALL + "entry","down",
               GALL + "hallway1_1","north",
               GALL + "hallway2_1","east",
    });
    items=({"hall","It is beautiful",
            "hallways","Feel free to see where they lead",
            "rooms","Go ahead!  See what's in them",
            "stairs","They lead back down to the entry way",
            "main stairs","They lead back down to the entry way",
    });
    set_light(1);
return 1;
  }
}
