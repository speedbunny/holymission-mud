inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,3,"vmona","players/goldsun/7-islands/ruby/monster/vulc_monster_a",0,
              2,2,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});
 dest_dir=({    PATH+"vulcano2", "north",
	        PATH+"vulcano5", "west",
		PATH+"vulcano10","south", 
		PATH+"vulcano7", "east"
	   });
}
 ::reset(arg);  
}

