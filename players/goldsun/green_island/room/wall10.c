inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_5_3","north",
	     PATH + "g_tower_3","south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



