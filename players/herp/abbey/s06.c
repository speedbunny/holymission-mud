
#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Near the end of the hallway";
     long_desc=
"This is an empty hall.  You can see the end of the hallway\n"+
"to the north, and a few more rooms to the west and east.\n";
     dest_dir=({ PATH+"/s07","north",
		 PATH+"/s05","south",
		 PATH+"/s06r","east",
		 PATH+"/s06l","west" });
  }
}
