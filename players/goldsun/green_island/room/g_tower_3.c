inherit "/players/goldsun/green_island/room/genTower_g";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "g_tower_4", "up",
	     PATH + "g_tower_2", "down",
	     PATH + "wall10",    "north",
             PATH + "wall11",    "south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



