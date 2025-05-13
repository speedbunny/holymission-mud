#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="East path";
     long_desc=
"The path is icey, you are freezing in the wind.  A small track leads east\n"+
"down a near perpendicular cliff.\n";
     dest_dir=({ PATH+"/o10","north",
		 PATH+"/o12","south" });
  }
}
