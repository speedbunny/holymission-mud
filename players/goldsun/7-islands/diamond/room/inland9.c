inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"wolf","players/goldsun/7-islands/diamond/monster/wolf",0,
       2,1,"bear","players/goldsun/7-islands/diamond/monster/ice_bear",0});

 dest_dir=({    PATH+"inland8", "north",
	        PATH+"ridge10","west",
		PATH+"ridge9", "south" 
	   });
 }
 ::reset(arg);  
}

