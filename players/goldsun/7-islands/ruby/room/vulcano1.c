inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,2,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});
 dest_dir=({    PATH+"coast1", "northeast",
	        PATH+"vulcano2","east",
		PATH+"vulcano5","south" 
	   });
}
 ::reset(arg);  
}

