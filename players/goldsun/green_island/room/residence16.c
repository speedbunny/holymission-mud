inherit "/players/goldsun/green_island/room/genResidence";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 clone_list=({1,2,"cyclops","/players/goldsun/green_island/monster/cyclops",
	           0});
 dest_dir=({ PATH + "residence17", "north"});

 }

 ::reset(arg);
 replace_program("/room/room");
}



