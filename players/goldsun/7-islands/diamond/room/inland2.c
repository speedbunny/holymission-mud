inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"man","players/goldsun/7-islands/diamond/monster/snow_man",0,
            2,1,"bear","players/goldsun/7-islands/diamond/monster/ice_bear",0});

 dest_dir=({    PATH+"inland6","east",
		PATH+"inland3","south" 
	   });
 }
 ::reset(arg);  
}

