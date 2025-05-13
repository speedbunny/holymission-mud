#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Courtyard";
     long_desc=
"You stand in the center of a vast courtyard.  You see monks bustling about\n"+
"their daily responsibilities.\n";
     dest_dir=({ PATH+"/e10","north",
		 PATH+"/e12","south" });
  }
}
