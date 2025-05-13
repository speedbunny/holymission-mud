inherit "/players/goldsun/nottingham/room/genWall";
#include "/obj/door.h"

#define PATH "/players/goldsun/nottingham/room/"

object obj_1, obj_2, key;

reset(arg){
 ::reset(arg);

if (arg) return;
 MAKE_DOORS("/players/goldsun/nottingham/room/wall4","tower",
	    "/players/goldsun/nottingham/room/tower_ne","out",
	    "iron","tower","Massive wooden door.\n",
	    1,0,1);
 MAKE_KEY( key, "iron", "tower" );
 transfer(key,"/players/goldsun/workroom");

 dest_dir=({ PATH + "wall3",  "south",
	     PATH + "road14", "southwest",
	     PATH + "wall5",  "west" });
}


