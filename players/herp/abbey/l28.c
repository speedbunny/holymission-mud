inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A small stairway in the labyrinth";
     long_desc=
"A stairway in the labyrinth somewhere.  You feel that you\n"+
"are very high now, and you begin to get a little dizzy.\n";
     dest_dir=({ PATH+"/l25","southdown",
		 PATH+"/l30","eastup",
		 PATH+"/l26","westup" });
  }
}
