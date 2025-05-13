inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="The maze has blue swirls of mist here.\n" +
              "You can't tell one direction from another.\n";

    dest_dir=({MAZE1 + "s44","south",
               MAZE1 + "s24","north",
                MAZE1 + "s31","east",
                MAZE1 + "t1","west",
    });
    items=({"maze","The maze looks different here..",
            "swirls","They seems strange here..",
            "mist","It looks strange here..",
    });
    set_light(1);
return 1;
RR;
}
