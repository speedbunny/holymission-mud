inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="The maze shifts about you, but you sense that\n" +
              "you are on the right track.\n";

    dest_dir=({MAZE1 + "r1","south",
               MAZE1 + "r1","north",
               MAZE1 + "r1","east",
               MAZE1 + "r3","west",
    });
    items=({"maze","A confusing maze",
    });
    set_light(1);
return 1;
RR;
}
