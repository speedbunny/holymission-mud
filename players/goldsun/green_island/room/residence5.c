inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence6", "north",
             PATH + "residence2", "east",
	     PATH + "residence4", "south",
	     PATH + "residence8", "west",
	     PATH + "residence10", "up"  });

 }

 ::reset(arg);
 replace_program("/room/room");
}



