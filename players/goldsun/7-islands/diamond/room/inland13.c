inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"wolf","players/goldsun/7-islands/diamond/monster/wolf",0,
            2,1,"yeti","players/goldsun/7-islands/diamond/monster/yeti",0});

 dest_dir=({    PATH+"ridge5",  "north",
	        PATH+"ridge6",  "east",
	  	PATH+"inland11","west" 
	   });
 }
 ::reset(arg);  
}

