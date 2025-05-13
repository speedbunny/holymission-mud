inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="The maze still shifts continuously, but you can\n" +
              "tell that you're getting REALLY close now!\n";

    dest_dir=({MAZE1 + "r1","south",
               MAZE1 + "r1","north",
               MAZE1 + "r5","east",
               MAZE1 + "r1","west",
    });
    items=({"maze","This maze is goofy",
    });
    set_light(1);
return 1;
RR;
}
