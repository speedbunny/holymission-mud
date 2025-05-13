inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A cheery forest";
    long_desc="The forest allows enough light in that you don't have to\n" +
              "strain to see your way.  You feel relaxed walking\n" +
              "through this woods.\n";

    dest_dir=({ATTACH + "forest1","south",
               ATTACH + "forest5","north",
    });
    items=({"forest","The forest seems peaceful",
            "tree","A fine young oak tree",
            "trees","They sway gently in the breeze",
    });
    set_light(1);
return 1;
RR;
}
