inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
    short_desc="Newbie Training Area";
    long_desc="Welcome to the newbie training area!\n" +
              "This area has easy monsters in it so that you can learn how\n" +
              "to fight and get experience.\n" +
              "Go ahead!  Look around for those monsters!\n" +
              "North is where the monsters are.  South is back\n" +
              "to the hut.\n";

    dest_dir=({ATTACH + "hut","south",
               TRAIN + "1_3","north",
    });
    items=({"area","This area is only for newbies",
    });
    set_light(1);
return 1;
RR;
}
