#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Chapel Hallway";
     long_desc=
"You are in a torch-lit hallway south of the sanctuary.  You see a door to\n"+
"the south.\n";
     items=({ "door","A plain old oak door" });
     dest_dir=({ PATH+"/e19","north",
		 PATH+"/e21","south" });
  }
}
