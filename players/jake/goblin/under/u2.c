inherit "room/room";
#include "/players/jake/defs.h"
reset (arg) {
 if (arg) return;
 set_light(1);
 short_desc = "Northern tunnel under the castle";
 long_desc  = "You stand in a small tunnel that is heading in a northern direction.\n"+
              "A slight breeze is coming from the north, giving you some hope that\n"+
              "there is a way out in that direction.\n";
 dest_dir = ({
              UN + "u3","north",
              UN + "u1","south",
            });
}
