#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A large room in the labyrinth";
     long_desc=
"You are in a large circular room somewhere in the center of the\n"+
"Labyrinth.  Books line the walls on shelves here.\n";
     dest_dir=({ PATH+"/l15","west",
		 PATH+"/l09","southeast",
		 PATH+"/l17","up" });
  }
}
