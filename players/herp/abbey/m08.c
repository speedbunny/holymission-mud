
#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Central Hallway";
     long_desc=
"You are in a hallway in the monks quarters. The hall extends north and\n"+
"south.  Rooms are to the east and west.\n";
     dest_dir=({ PATH+"/m09","north",
		 PATH+"/m07","south",
		 PATH+"/m08r","east",
		 PATH+"/m08l","west" });
  }
}
