inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,1,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence23", "north",
             PATH + "residence25", "west",
	     PATH + "residence19", "east"  });

 }

 ::reset(arg);
 replace_program("/room/room");
}



