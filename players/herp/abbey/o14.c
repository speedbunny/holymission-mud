#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="East path";
     long_desc=
"An icey track that threads it's way along the east wall of the abbey.\n";
     dest_dir=({ PATH+"/o13","north",
		 PATH+"/o15","south" });
  }
}
