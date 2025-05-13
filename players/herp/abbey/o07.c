#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Intersection";
     long_desc=
"A narrow path follows the abbey wall, going either west or south.  To the\n"+
"north is a well-traveled path with many footprints.  To the east a faint\n"+
"trace moves down the hill.\n";
     dest_dir=({ PATH+"/o0701","north",
		 PATH+"/o09","south",
		 PATH+"/o06","west",
		 PATH+"/o08","east" });
  }
}
