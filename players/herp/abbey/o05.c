#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Northern Path";
     long_desc=
"A footpath following along the northern wall of the Abbey.\n";
     dest_dir=({ PATH+"/e07","west",
		 PATH+"/o06","east" });
  }
}
