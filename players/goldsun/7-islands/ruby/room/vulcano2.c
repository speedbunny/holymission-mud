inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,3,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});
 dest_dir=({    PATH+"vulcano1", "west",
		PATH+"vulcano6", "south",
		PATH+"vulcano3","east" 
	   });
}
 ::reset(arg);  
}

