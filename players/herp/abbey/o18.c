#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Narrow Path";
     long_desc=
"An icey intersection with a path leading south.  You see string-tied\n" +
"bundles of wood stacked here and there around the intersection.\n";
     dest_dir=({ PATH+"/o17","east",
		 PATH+"/o19","west",
		 PATH+"/o18t1","south" });
  }
}
