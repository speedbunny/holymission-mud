inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,2,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence32", "south",
             PATH + "residence36", "west",
	     PATH + "residence30", "east"  });

 }

 ::reset(arg);
 replace_program("/room/room");
}



