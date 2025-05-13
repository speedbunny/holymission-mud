inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "new7";
  long_desc = 
        "You are in the area directly south of Jake's garden.\n"
        "The fresh air almost puts you to sleep.\n";
 DD = ({
  NEW + "gard10","north",
  NEW + "new6","south",
});

replace_program("room/room");
}

