inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="As the maze continuously seems to move, you\n" +
              "sense that you're progressing well.\n";

    dest_dir=({MAZE1 + "r1","south",
               MAZE1 + "r4","north",
               MAZE1 + "r1","west",
               MAZE1 + "r1","east",
    });
    items=({"maze","This maze is nuts",
    });
    set_light(1);
return 1;
RR;
}
