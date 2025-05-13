#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Stairwell";
     long_desc=
"You stand in a rough hewn stairwell.  You hear moisture dripping and smell the\n" +
"foul odor of rot.\n";
     dest_dir=({ PATH+"/g02","up",
		 PATH+"/g04","west" });
  }
}
