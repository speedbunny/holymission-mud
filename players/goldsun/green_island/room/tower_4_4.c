inherit "/players/goldsun/green_island/room/genTower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_4_5", "up",
	     PATH + "wall7",     "west",
	     PATH + "wall8",     "south",
	     PATH + "tower_4_3", "down"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



