inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="The maze has blue swirls of mist here.\n" +
              "You can't tell one direction from another.\n";

    dest_dir=({MAZE1 + "s34","south",
               MAZE1 + "s14","north",
                MAZE1 + "s21","east",
                MAZE1 + "s23","west",
    });
    items=({"maze","A confusing maze",
            "swirls","They make everything blurry",
            "mist","It makes everything blurry",
    });
    set_light(1);
return 1;
RR;
}
