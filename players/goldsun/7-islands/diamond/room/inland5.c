inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){

 dest_dir=({    PATH+"ridge3", "north",
	        PATH+"ridge4", "east",
	        PATH+"inland6","south",
		PATH+"ridge2", "west" 
	   });
}
 ::reset(arg);  
}

