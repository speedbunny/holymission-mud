#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="West Path";
     long_desc=
"The path continues north and south.  There is a narrow track leading west.\n";
     dest_dir=({ PATH+"/o26","north",
		 PATH+"/o24","south",
		 PATH+"/o2501","west" });
  }
}
