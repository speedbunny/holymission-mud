inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "wall14", "northwest",
	     PATH + "road7",  "northeast",
	     PATH + "wall16", "southeast" });
}


