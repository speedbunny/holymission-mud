inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "wall8" , "northeast",
	     PATH + "road11", "southeast",
	     PATH + "wall10", "southwest" });
}


