#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Southern Courtyard";
     long_desc=
"You are in the southwestern section of the courtyard.  You see the soldiers\n"+
"of the holy mother church coming and going about the building to the west.\n"+
"You see a huge black tower to the south.\n";
     dest_dir=({ PATH+"/s01","east",
		 PATH+"/s03","west" });
  }
}
