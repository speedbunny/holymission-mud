inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){

 dest_dir=({    PATH+"inland2","north",
	        PATH+"inland7","east",
		PATH+"inland1","west" 
	   });
}
 ::reset(arg);  
}

