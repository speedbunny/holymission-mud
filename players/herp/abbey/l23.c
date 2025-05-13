#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A huge room in the labyrinth";
     long_desc=
"This is the biggest room you've seen yet in the entire labyrinth.\n"+
"There are hundreds of books on the walls in this room.\n";
     dest_dir=({ PATH+"/l25","up",
		 PATH+"/l20","down",
		 PATH+"/l22", "east" });
  }
}
