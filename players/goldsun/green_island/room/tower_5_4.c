inherit "/players/goldsun/green_island/room/genTower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_5_5", "up",
	     PATH + "wall9",     "west",
	     PATH + "tower_5_3", "down"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



