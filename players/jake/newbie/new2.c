inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "new2";
  long_desc = 
        "You are travelling east on a small dirt path.\n"
        "The dirt feels real soft on your feet.\n";
 DD = ({
  NEW + "new1","west",
  NEW + "new3","north",
});
replace_program("room/room");
}

