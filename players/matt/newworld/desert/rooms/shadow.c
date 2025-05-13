inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Cliff Shadow";
  long_desc =
    "    You stand next to part of the huge series of cliffs which\n" +
    "surround this desert. The shadow of the cliffs provides a cool\n" +
    "respite from the severe, acrid heat of the sands around you.\n";

  items = ({
    "desert", "Looking at it makes you want to stay where you are",
    "shadow", "You think you can see things moving in the darkness",
    "sands", "The sands are dark and cold here",
  });
}
     
no_way() {
  write("The cliffs block your way.\n");
  return 1;
}
