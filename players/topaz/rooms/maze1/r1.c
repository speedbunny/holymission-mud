inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="You have entered a maze.\n" +
              "This is a magical maze that seems to swirl about\n" +
              "you even as you stand here.\n" +
              "Hopefully you'll be able to find your way out!\n";

    dest_dir=({MAZE1 + "r1","south",
               MAZE1 + "r1","north",
               MAZE1 + "r1","west",
               MAZE1 + "r2","east",
    });
    items=({"maze","This maze is confusing",
    });
    set_light(1);
return 1;
RR;
}
