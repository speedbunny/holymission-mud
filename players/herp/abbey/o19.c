#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="South Path";
     long_desc=
"You are on a narrow, icey path to the south of the abbey wall.  You see\n"+
"footprints in the snow and smell the reek of burning flesh.\n";
     dest_dir=({ PATH+"/o18","east",
		 PATH+"/o20","west" });
  }
}
