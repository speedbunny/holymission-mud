inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,3,"wolf","players/goldsun/7-islands/diamond/monster/wolf",0,
            2,1,"bear","players/goldsun/7-islands/diamond/monster/ice_bear",0,
	    3,1,"fox","players/goldsun/7-islands/diamond/monster/fox",0});

 dest_dir=({    PATH+"inland5", "north",
	        PATH+"inland10","east",
		PATH+"inland7", "south",
	  	PATH+"inland2", "west" 
	   });
 }
 ::reset(arg);  
}

