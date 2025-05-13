#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A small stairway in the labyrinth";
     long_desc=
"This stairway is slightly different than the others.\n"+
"You notice small inscriptions on the stairs, buy they\n"+
"are too small to read.\n";
     dest_dir=({ PATH+"/l21","up",
		 PATH+"/l13","southeast" });
  }
}
