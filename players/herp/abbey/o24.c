#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="West Path";
     long_desc=
"A narrow track following the wall of the abbey.\n";
     dest_dir=({ PATH+"/o25","north",
		 PATH+"/o23","south" });
  }
}
