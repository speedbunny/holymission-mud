#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="The entrance to the soldier barracks";
     long_desc=
"To the north you see living quarters.  You see soldiers coming and going.  To\n"+
"the south you see a huge, forbidding black tower.\n";
     items=({ "tower","A huge black tower with no windows" });
     dest_dir=({ PATH+"/s04","north",
		 PATH+"/s02","east",
		 PATH+"/l01","south" });
  }
}
