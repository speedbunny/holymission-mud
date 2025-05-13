inherit "room/room";
#include "/players/jake/defs.h"
reset (arg) {
 if (arg) return;
 set_light(1);
 short_desc = "Under the castle";
 long_desc  = "You are standing in what appears to be an underground network.\n" +
              "There are small caves that lead off to the north, south, and east.\n" +
              "There seems to be no possible way of getting back up through\n" +
              "the way you came, so you can only hope that one of these tunnels\n" +
              "lead out.\n";
 items =({
              "caves","Small tunnels really",
              "tunnels","Small tunnels that lead in various directions",
        });
 DD = ({
       UN + "u2","north",
       UN + "u20","south",
       UN + "u4","east",

          });
}
