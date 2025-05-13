inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A large stairway in the labyrinth";
     long_desc=
"You are walking on a HUGE stairway in the labyrinth somewhere.\n"+
"Your legs are beginning to give out, and you wonder how much\n"+
"longer you can take this.\n";
     dest_dir=({ PATH+"/l13","down",
		 PATH+"/l17","eastup" });
  }
}
