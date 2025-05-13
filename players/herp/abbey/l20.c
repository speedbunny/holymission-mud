#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A stairway in the labyrinth";
     long_desc=
"You are on a smaller staircase\n"+
"There is not much of interest here.\n";
     dest_dir=({ PATH+"/l23","up",
		 PATH+"/l15","down" });
  }
}
