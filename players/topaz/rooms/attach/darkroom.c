inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A very dark room";
    long_desc="You can see nothing.\n";

    dest_dir=({MAZE1 + "r1","south",
               MAZE1 + "r1","north",
               MAZE1 + "r1","east",
               MAZE1 + "r1","west",
    });
    items=({"room","You can see nothing",
    });
    set_light(-5);
return 1;
RR;
}
