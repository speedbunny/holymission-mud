inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence15", "north",
             PATH + "residence12", "east",
	     PATH + "residence14", "south",
	     PATH + "residence17", "west",
	     PATH + "residence23", "up",
             PATH + "residence5", "down"    });

 }

 ::reset(arg);
 replace_program("/room/room");
}



