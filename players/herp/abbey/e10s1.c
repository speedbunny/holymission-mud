#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Courtyard";
     long_desc=
"You hear the sounds of domesticated animals all around you.\n";
     dest_dir=({ PATH+"/e09s1","north",
		 PATH+"/e11s1","south" });
  }
}
