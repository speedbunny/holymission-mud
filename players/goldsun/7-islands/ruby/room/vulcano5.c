inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 dest_dir=({    PATH+"vulcano1", "north",
	        PATH+"vulcano6", "east",
		PATH+"vulcano9", "south" 
	   });
}
 ::reset(arg);  
}

