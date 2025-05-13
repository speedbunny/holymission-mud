inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A stairway in the labyrinth";
     long_desc=
"You are on a long stairway in the labyrinth.\n"+
"You feel your arms and legs begin to ache.\n";
     dest_dir=({ PATH+"/l21","eastup",
		 PATH+"/l22","westup",
		 PATH+"/l18","westdown",
		 PATH+"/l12","down" });
  }
}
