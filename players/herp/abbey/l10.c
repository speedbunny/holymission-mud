#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A set of stairs";
     long_desc=
"You are walking on a large set of stairs.\n"+
"Your legs are beginning to get tired.\n";
     dest_dir=({ PATH+"/l13","up",
		 PATH+"/l07","down" });
  }
}
