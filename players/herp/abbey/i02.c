#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Snow Pass";
     long_desc=
"You wearily trudge through the snow-covered pass over\n"+
"the shoulder of the mountain.  You hear the wind and feel\n"+
"its sharp bite through your clothes.  You see a well-traveled\n"+
"path south, marked by the passage of many people and carts.\n";
     dest_dir=({ PATH+"/i01","west",
		 PATH+"/e01","south" });
  }
}
