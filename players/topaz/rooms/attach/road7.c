inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are on Village Road South.\n" +
              "There are trees to the south and a big building is to the\n" +
              "north, although there is no entrance on this side.\n" +
              "Village Road South goes east and west from here.\n";

    dest_dir=({ATTACH + "road8","east",
               ATTACH + "road6","west",
    });
    items=({"road","The road looks like it is used a lot",
            "building","It looks impressive.  You wonder what could be in it",
            "big building","It looks impressive.  You wonder what could be in it",
            "tree","There are a few ash trees and some birch trees here",
           "trees","There are some nice white birch trees and some others",
    });
    set_light(1);
    smell="The forest smells clean and fresh.";
return 1;
RR;
}
