#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Chapel Hallway";
     long_desc=
"You are in a torch-lit hallway south of the sanctuary.\n";
     dest_dir=({ PATH+"/e17","north",
		 PATH+"/e19","south" });
  }
}
