inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_1_4", "east",
	     PATH + "wall2",     "west"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



