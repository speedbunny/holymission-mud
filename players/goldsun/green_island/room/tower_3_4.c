inherit "/players/goldsun/green_island/room/genTower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_3_5", "up",
	     PATH + "wall5",     "north",
	     PATH + "wall4",     "east",
	     PATH + "tower_3_3", "down"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



