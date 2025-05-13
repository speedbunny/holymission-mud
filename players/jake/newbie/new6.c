inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "new6";
  long_desc = 
        "You are getting closer to Jake's garden.\n"
        "You can hear the birds chirping, and smell the clean air.\n";
  DD = ({
  NEW + "new7","north",
  NEW + "new5","south",

});
replace_program("room/room");
}

