inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence24", "north",
             PATH + "residence20", "east",
	     PATH + "residence22", "south",
	     PATH + "residence26", "west",
	     PATH + "residence32", "up",
             PATH + "residence10", "down"    });

 }

 ::reset(arg);
 replace_program("/room/room");
}



