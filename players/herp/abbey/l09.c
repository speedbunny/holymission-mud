#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A small set of stairs";
     long_desc=
"You are walking on a small set of stairs.\n"+
"You stare in awe at the hugeness of this place.\n"+
"Will you ever get out?\n";
     dest_dir=({ PATH+"/l06","down",
		 PATH+"/l12","northwest",
		 PATH+"/l13","northeast" });
  }
}
