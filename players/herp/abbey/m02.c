#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Cells Entrance";
     long_desc=
"You stand before a large stone building, apparently monk living quarters.\n"+
"To the south is the dispensary and of course, the graveyard.\n";
     dest_dir=({ PATH+"/m07","north",
		 PATH+"/m03","south",
		 PATH+"/m01","west" });
  }
}
