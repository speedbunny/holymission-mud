inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "new5";
  long_desc = 
        "It seems to be cooling off here.\n"
        "Is that snow to the east?\n"
        "The ground is getting harder here.\n";
  DD = ({
   NEW + "new4","west",
  NEW + "new5a","east",
  NEW + "new6","north",
  });

replace_program("room/room");
}

