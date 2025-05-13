inherit "/players/goldsun/nottingham/room/genWall";
#include "/obj/door.h"

#define PATH "/players/goldsun/nottingham/room/"

object obj_1, obj_2;

reset(arg){
 ::reset(arg);

if (arg) return;
 MAKE_DOORS("/players/goldsun/nottingham/room/wall16","tower",
	    "/players/goldsun/nottingham/room/tower_sw","out",
	    "iron","tower","Massive wooden door.\n",
	    1,0,1);

 dest_dir=({ PATH + "wall15", "northwest",
	     PATH + "wall17", "east" });
}


