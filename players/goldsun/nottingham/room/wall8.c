inherit "/players/goldsun/nottingham/room/genWall";
#include "/obj/door.h"

#define PATH "/players/goldsun/nottingham/room/"

object obj_1, obj_2, key;

reset(arg){
 ::reset(arg);

if (arg) return;
 MAKE_DOORS("/players/goldsun/nottingham/room/wall8","tower",
	    "/players/goldsun/nottingham/room/tower_nw","out",
	    "iron","tower","Massive wooden door.\n",
	    1,0,1);

 dest_dir=({ PATH + "wall7", "east",
	     PATH + "wall9", "southwest" });
}


