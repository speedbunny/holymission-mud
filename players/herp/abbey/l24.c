#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A stairway in the labyrinth";
     long_desc=
"You are climbing on a stairway somewhere in the labyrinth.\n"+
"You wonder how this place was built in the first place.\n";
     dest_dir=({ PATH+"/l26","up",
		 PATH+"/l22","down" });
  }
}
