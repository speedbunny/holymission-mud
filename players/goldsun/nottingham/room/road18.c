inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Coal Circus";
 dest_dir=({ PATH + "wall11", "north",
	     PATH + "gates_w", "west",
	     PATH + "wall13", "south", 
	     PATH + "road17", "east" });
}


