#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="North Path";
     long_desc=
"You struggle to keep your footing on the icy path.\n";
     dest_dir=({ PATH+"/o05","west",
		 PATH+"/o07","east" });
  }
}
