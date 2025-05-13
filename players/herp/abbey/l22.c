inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room in the labyrinth";
     long_desc=
"A room somewhere deep in the labyrinth.\n"+
"Books line the walls on shelves here.\n";
     dest_dir=({ PATH+"/l24","up",
		 PATH+"/l23","west",
		 PATH+"/l17","eastdown" });
  }
}
