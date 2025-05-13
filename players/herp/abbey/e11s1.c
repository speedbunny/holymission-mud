#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Courtyard";
     long_desc=
"You hear the screems of a pig in acute distress to the east.  You smell\n"+
"fresh blood and the foul odor of putrefraction.\n";
     dest_dir=({ PATH+"/e10s1","north",
		 PATH+"/e12s1","south",
		 PATH+"/e11s2","east" });
  }
}
