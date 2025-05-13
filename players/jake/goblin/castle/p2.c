inherit "room/room";

#include "/players/jake/defs.h"

reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "In the pasture";
 long_desc  = "You are standing in the horse pasture of the goblin castle.\n" +
              "Small rocks lie scattered about, and a wooden fence prevents\n" +
              "any travel west.\n";
 items = ({ 
   "rocks","Small rocks",
   "fence","A wooden fence that keeps the horses in the pasture",
   });
 DD = ({
  CAS + "p1","southeast",
  CAS + "p4","north",
 });

replace_program("room/room");
}
