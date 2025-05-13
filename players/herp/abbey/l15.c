#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room in the labyrinth";
     long_desc=
"You have entered an average-looking room in the labyrinth.\n"+
"Books line the shelves on the walls.\n";
     dest_dir=({ PATH+"/l11","down",
		 PATH+"/l12","east",
		 PATH+"/l20","up" });
  }
}
