inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "gates_w", "northwest",
	     PATH + "road18", "north",
	     PATH + "road17", "northeast",
	     PATH + "wall14", "southeast" });
}


