inherit "/players/goldsun/green_island/room/genTower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_5_4", "up",
	     PATH + "tower_5_2", "down",
	     PATH + "wall10",    "south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



