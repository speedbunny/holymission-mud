inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_4_4", "north",
	     PATH + "wall9",     "east"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



