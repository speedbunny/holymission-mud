inherit "/players/goldsun/green_island/room/genTower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_2_4", "up",
	     PATH + "tower_2_2", "down"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



