#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Hallway";
     long_desc=
"You are in a short hallway.  To the south is the Great Hall,\n"+
"to the north, a stairwell.\n";
     dest_dir=({ PATH+"/c15","north",
		 PATH+"/c13","south" });
  }
}
