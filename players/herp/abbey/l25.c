#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="An interesting room in the labyrinth";
     long_desc=
"This room is different from the others, the books seem a little\n"+
"shinier, and this room looks a bit more used.\n";
     dest_dir=({ PATH+"/l27","east",
		 PATH+"/l28","northup",
		 PATH+"/l29","up",
		 PATH+"/l23","down",
		 PATH+"/l21","eastdown" });
  }
}
