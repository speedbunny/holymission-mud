inherit "/players/goldsun/nottingham/room/genWall";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "wall9" , "northeast",
	     PATH + "wall11", "southwest" });
}


