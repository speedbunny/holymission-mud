inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A cheery forest";
    long_desc="The forest is still light enough to see by.\n" +
              "You feel at ease here.\n" +
              "There is some rustling in the bushes to the south.\n";

    dest_dir=({ATTACH + "forest2","east",
               ATTACH + "forest7","south",
    });
    items=({"forest","The forest is peaceful here",
            "bushes","They look harmless enough",
            "bush","There are many bushes",
    });
    set_light(1);
return 1;
RR;
}
