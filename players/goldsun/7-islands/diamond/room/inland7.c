inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,3,"wolf","players/goldsun/7-islands/diamond/monster/wolf",0,
            2,1,"sighard","players/goldsun/7-islands/diamond/monster/wizard",0,
	    3,1,"frost","players/goldsun/7-islands/diamond/monster/frost",0,
	    4,1,"cermor","players/goldsun/7-islands/diamond/monster/cermor",0});

 dest_dir=({    PATH+"inland6", "north",
	        PATH+"inland11","east",
		PATH+"inland8", "south",
	  	PATH+"inland3", "west" 
	   });
 }
 ::reset(arg);  
}

