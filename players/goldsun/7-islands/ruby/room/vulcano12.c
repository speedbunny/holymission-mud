inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 dest_dir=({    PATH+"vulcano8", "north",
	        PATH+"vulcano11","west",
		PATH+"vulcano16","south" 
	   });
}
 ::reset(arg);  
}

