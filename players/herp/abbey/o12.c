#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="On the eastern path";
     long_desc=
"You struggle to keep your footing on the icey path.\n";
     dest_dir=({ PATH+"/o11","north",
		 PATH+"/o13","south" });
  }
}
