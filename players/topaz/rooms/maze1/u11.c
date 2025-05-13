inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="There are red swirls of mist here.\n";

    dest_dir=({MAZE1 + "u15","south",
               MAZE1 + "v1","north",
                MAZE1 + "u14","west",
    });
    items=({"maze","A confusing maze",
            "swirls","Just some pretty mist",
            "mist","It looks nice",
    });
    set_light(1);
return 1;
RR;
}
