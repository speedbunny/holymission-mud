inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,4,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence33", "north",
             PATH + "residence29", "east",
	     PATH + "residence31", "south",
	     PATH + "residence35", "west",
	     PATH + "residence39", "up",
             PATH + "residence23", "down"    });

 }

 ::reset(arg);
 replace_program("/room/room");
}



