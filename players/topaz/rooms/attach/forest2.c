inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A cheery forest";
    long_desc="The forest doesn't seem to get any darker, the farther\n" +
              "in you go.  The trees here seem young and vibrant.\n" +
              "It seems you have nothing to fear in this forest.\n";

    dest_dir=({ATTACH + "forest1","southeast",
               ATTACH + "forest4","west",
    });
    items=({"forest","The forest is calm here",
            "tree","A young ash tree",
            "trees","They sway gently in the breeze",
    });
    set_light(1);
return 1;
RR;
}
