inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"frost","players/goldsun/7-islands/diamond/monster/wolf",0});

 dest_dir=({    PATH+"inland10","north",
	        PATH+"inland13","east",
		PATH+"inland12","south",
	  	PATH+"inland7", "west" 
	   });
 }
 ::reset(arg);  
}

