inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "new1";
  long_desc = 
        "A strange and odd looking dirt path.\n"
      "Far off to the east you think you can hear singing.\n"
      "Maybe you should go see who or what is singing?.\n";
 items = ({ "path", "A dirt path" });
 DD = ({
  JA + "path2","west",
  NEW + "new2","east",
  });
}
