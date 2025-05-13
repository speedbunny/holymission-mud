inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A cheery forest";
    long_desc="The forest is a beautiful sight after that horrible maze!\n" +
              "You are glad to get out.\n" +
              "However, if you need to enter it again for whatever reason,\n" +
              "it is down from here.\n";

    dest_dir=({ATTACH + "forest5","east",
               MAZE1 + "r1","down",
    });
    items=({"forest","You're glad to be out of that maze",
    });
    set_light(1);
return 1;
RR;
}
