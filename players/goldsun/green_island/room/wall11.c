inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "g_tower_3","north",
	     PATH + "tower_1_3","south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



