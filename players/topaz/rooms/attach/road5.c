inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are on Village Road South.\n" +
              "There is a little hut to the west and you still can see a\n" +
              "big building to the east, although there is no entrance on\n" +
              "this side.\n" +
              "Village Road South goes north and south from here.\n";

    dest_dir=({ATTACH + "road6","south",
               ATTACH + "road4","north",
               ATTACH + "hut","west",
    });
    items=({"road","The road is well used",
            "hut","It is small, but something about it seems strange",
            "building","A big grey building that intrigues you",
            "big building","A big grey building that intrigues you",
    });
    set_light(1);
    smell="You can still smell the fresh trees.";
return 1;
RR;
}
