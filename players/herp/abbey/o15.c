#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Intersection";
     long_desc=
"The narrow icey path continues to hug the abbey wall, going north or west.\n"+
"Small tracks diverge here, going south and east.\n";
     dest_dir=({ PATH+"/o14","north",
		 PATH+"/o1501","south",
		 PATH+"/o1502","east",
		 PATH+"/o16","west" });
  }
}
