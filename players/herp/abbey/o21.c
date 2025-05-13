#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Intersection";
     long_desc=
"The icey path hugs the wall going north and east.  To the west and south\n"+
"are well-traveled paths.\n";
     dest_dir=({ PATH+"/o22","north",
		 PATH+"/o2101","south",
		 PATH+"/o20","east",
		 PATH+"/o2102","west" });
  }
}
