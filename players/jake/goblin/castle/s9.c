inherit "room/room";

#include "/players/jake/defs.h"

reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "The end of the stables";
 long_desc  = "You are standing at the end of the stables.  An open wooden gate\n" +
              "allows entrance into a pasture to the north.  Stables are to the\n" +
              "east and west, and the rest of the barn is to the south.\n";
 items = ({
  "gate","A wooden gate",
 });
 DD = ({
  CAS + "s6","south",
  CAS + "s10","east",
  CAS + "s11","west",
  CAS + "p1","north",
 });

replace_program("room/room");
}
