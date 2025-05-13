#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Northern Path";
     long_desc=
"An icy, rocky path that follows along the northern wall of the abbey.\n";
     dest_dir=({ PATH+"/e07","east",
		 PATH+"/o03","west" });
  }
}
