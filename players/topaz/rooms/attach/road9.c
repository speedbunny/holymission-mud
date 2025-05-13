inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are on Village Road South.\n" +
              "There are trees to the east and a big building to the\n" +
              "west, but there is no entrance on this side.\n" +
              "Village Road South goes north and south from here.\n";

    dest_dir=({ATTACH + "road8","south",
               ATTACH + "road2","north",
    });
    items=({"road","The road is very worn",
            "building","It is a big building." +
                       "It makes you want to find out what's in it",
            "big building","It is a huge building." +
                           "It makes you want to find out what's in it",
            "tree","There are plenty of oaks, maples and beech trees",
            "trees","There are some strong oak trees and huge willows",
    });
    set_light(1);
    smell="The trees refresh and excite your senses.";
return 1;
RR;
}
