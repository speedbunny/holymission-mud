inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,3,"wolf","players/goldsun/7-islands/diamond/monster/wolf",0,
            2,1,"man","players/goldsun/7-islands/diamond/monster/snow_man",0});

 dest_dir=({    PATH+"inland7", "north",
		PATH+"inland4", "west",
	  	PATH+"inland9", "south" 
	   });
 }
 ::reset(arg);  
}

