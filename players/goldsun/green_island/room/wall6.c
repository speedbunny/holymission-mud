inherit "/players/goldsun/green_island/room/genWall";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "residence31", "north",
	     PATH + "wall5", "south"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



