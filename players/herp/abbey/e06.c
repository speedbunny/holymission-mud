#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="At the foot of the Abbey";
     long_desc=
"You walk carefully along a bitter and snow-crusted trail beside a frozen "+
"stream.\n" +
"You hear a dog howling and smell wood smoke.  The brush is sparse, dark and\n"+
"barren.\n";
     dest_dir=({ PATH+"/e05","north",
		 PATH+"/e07","south" });
  }
}
