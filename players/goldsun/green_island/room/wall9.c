inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "wall8", "west",
	     PATH + "tower_5_4", "east"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



