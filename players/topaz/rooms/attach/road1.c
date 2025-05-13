inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are at the east end of Village Road South.\n" +
              "There are trees north and south of you.\n" +
              "The road goes west from here and a well used path leads\n" +
              "east.\n";

    dest_dir=({ATTACH + "road2","west",
               ATTACH + "path1","east",
    });
    items=({"road","The road looks like it is used often",
            "path","It is very muddy from the heavy travel it receives",
            "tree","There are lots of them.  Oaks, maples, and some other kinds",
            "trees","They are strong and healthy looking trees",
    });
    set_light(1);
    smell="You smell the fresh, clean air given off by the trees.";
return 1;
RR;
}
