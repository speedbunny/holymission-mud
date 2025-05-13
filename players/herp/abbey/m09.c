#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="North End of Hallway";
     long_desc=
"You strand at the north end of the hallway in the monks quarters.\n";
     dest_dir=({ PATH+"/m10","north",
		 PATH+"/m08","south",
		 PATH+"/m09r","east",
		 PATH+"/m09l","west" });
  }
}
