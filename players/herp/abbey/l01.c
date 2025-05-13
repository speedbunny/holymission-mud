#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Library Steps";
     long_desc=
"You stand on the steps leading into the greatest library in Christendom.\n"+
"To your north you see soldiers of the holy mother church entering a building.\n";
     dest_dir=({ PATH+"/s03","north",
		 PATH+"/l02","south" });
  }
}
