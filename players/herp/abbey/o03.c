#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="North Path";
     long_desc=
"A narrow icey path.  The smell of wood smoke is strong in the air.\n";
     dest_dir=({ PATH+"/o04","east",
		 PATH+"/o02","west" });
  }
}
