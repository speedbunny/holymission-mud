inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){

 dest_dir=({    PATH+"inland6", "west",
		PATH+"inland11", "south"
	   });
 }
 ::reset(arg);  
}

