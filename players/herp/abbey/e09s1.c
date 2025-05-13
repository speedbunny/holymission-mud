#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Courtyard";
     long_desc=
"You smell and hear the presence of domesticated animals kept in close\n"+
"quarters nearby.  The stench makes your eyes burn, and turns your\n" +
"stomach.\n";
     dest_dir=({ PATH+"/e09s2","east",
		 PATH+"/e0804","north",
		 PATH+"/e10s1","south" });
  }
}
