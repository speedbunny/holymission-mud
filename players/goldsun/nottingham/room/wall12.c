inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "wall11", "northeast",
	     PATH + "road18", "east",
	     PATH + "wall13", "southeast" });
}


