inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "Hallway in the stables";
 long_desc  = "You are in the stables, taking care not to step in any of the\n" +
              "horse manure that is piled here.  Hopefully the goblins will\n" +
              "come clean this up before too much longer.  More stables are\n" +
              "to your west and east.\n";
 items = ({
  "pile","A stinky pile of horse manure",
  "manure","A stinky pile of horse manure",
         });
 DD = ({
   CAS + "s7","west",
   CAS + "s8","east",
   CAS + "s3","south",
   CAS + "s9","north",
 });

replace_program("room/room");
}

