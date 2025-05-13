#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Bottom Landing";
     long_desc=
"You are at the base of a stone stairwell.  South is the winery.\n";
     dest_dir=({ PATH+"/c15","up",
		 PATH+"/c17","south" });
  }
}
