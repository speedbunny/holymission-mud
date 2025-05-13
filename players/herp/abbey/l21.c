inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A small room in the labyrinth somewhere";
     long_desc=
"You are in a small room in the labyrinth somewhere.\n"+
"Books line the walls on the shelves here.\n";
     dest_dir=({ PATH+"/l17","westdown",
		 PATH+"/l25","westup",
		 PATH+"/l19", "down" });
  }
}
