inherit "room/room";

#include "/players/jake/defs.h"

reset (arg) {
 if(arg) return;
 set_light(1);
 short_desc = "Hallway between some stables";
 long_desc = "You are standing in a hallway between horse stables.  The hall\n" +
             "and more stables extends to the north, and a hall back to the\n" +
             "castle is to the south.  There is an empty stable to your east\n" +
             "and a black horse occupies the stable to your west.\n";
 items = ({
  "stables","Wooden stables that hold horses",
  });
 DD = ({
        CAS + "s4","east",
        CAS + "s5","west",
        CAS + "s6","north",
        CAS + "s2","south",
      });
}
