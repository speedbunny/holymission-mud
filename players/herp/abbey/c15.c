#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Stairwell";
     long_desc=
"You stand on a wide flight of stairs.  The stone treads are curvate from\n"+
"years of heavy use.\n";
     dest_dir=({ PATH+"/c14","south",
		 PATH+"/c16","down" });
  }
}
