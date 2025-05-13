inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are on Village Road South.\n" +
              "Trees line the road to the north and there is a big\n" +
              "building to the south.\n" +
              "The road moves east and west of here.\n";

    dest_dir=({ATTACH + "road2","east",
               ATTACH + "road4","west",
               GALL + "entry","south",
    });
    items=({"road","The road looks well travelled",
            "building","It is the famous WILLIEO'S GALLERIA!\n" +
                       "Unfortunately, it's closed for renovations right now",
            "big building","It is the famous WILLIEO'S GALLERIA!\n" +
                           "Unfortunately, it's closed for renovations right now",
                       "Unfortunately, it's closed for renovations right now",
            "tree","There are some oaks, larches and maples",
            "trees","They look lovely.  There are some oaks, some" +
                    "beeches and some ash trees.",
    });
    set_light(1);
    smell="The forest smells cool and refreshing.";
return 1;
RR;
}
