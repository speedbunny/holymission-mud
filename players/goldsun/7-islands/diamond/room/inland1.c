inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"man","players/goldsun/7-islands/diamond/monster/snow_man",0});

 dest_dir=({    PATH+"pass",   "west",
	        PATH+"inland3","east",
		PATH+"ridge11","south" 
	   });
}
 ::reset(arg);  
}

