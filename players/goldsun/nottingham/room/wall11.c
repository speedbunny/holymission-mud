inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "wall10", "northeast",
	     PATH + "road17", "southeast",
	     PATH + "road18", "south",
	     PATH + "gates_w", "southwest"});
}


