inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 dest_dir=({    PATH+"vulcano9", "north",
	        PATH+"vulcano14","east"
	   });
}
 ::reset(arg);  
}

