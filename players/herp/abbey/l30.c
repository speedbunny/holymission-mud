inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="The highest room in the labyrinth";
     long_desc=
"You are in a very high room in the labyrinth.\n"+
"You begin to feel a slight bit of dizzyness.\n"+
"Books line the walls on shelves here.\n";
     dest_dir=({ PATH+"/l29","down",
		 PATH+"/l28","westdown" });
  }
}
