inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "wall6", "north",
	     PATH + "tower_3_4", "south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



