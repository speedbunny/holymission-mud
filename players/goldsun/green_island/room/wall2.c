inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "wall1",    "east",
	     PATH + "tower_2_4","west"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



