inherit "/players/goldsun/green_island/room/genTower_g";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "g_tower_3", "up",
	     PATH + "gates",  "down"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



