inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "wall4",    "west",
	     PATH + "tower_2_4","south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



