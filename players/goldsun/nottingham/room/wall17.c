inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "wall16", "west",
	     PATH + "road6",  "north",
	     PATH + "wall18", "east" });
}


