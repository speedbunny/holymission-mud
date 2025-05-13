#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room up high in the labyrinth";
     long_desc=
"You are in a high room in the labyrinth.\n",
"Books line the walls on shelves here.\n";
     dest_dir=({ PATH+"/l30","up",
		 PATH+"/l25","down" });
  }
}
