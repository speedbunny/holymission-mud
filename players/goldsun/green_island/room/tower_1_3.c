inherit "/players/goldsun/green_island/room/genTower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_1_4", "up",
	     PATH + "tower_1_2", "down",
	     PATH + "wall11",    "north"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



