inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 dest_dir=({    PATH+"coast4", "northeast",
	        PATH+"vulcano3","west",
		PATH+"vulcano8","south" 
	   });
}
 ::reset(arg);  
}

