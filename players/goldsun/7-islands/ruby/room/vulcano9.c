inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"vmona","players/goldsun/7-islands/ruby/monster/vulc_monster_a",0,
          2,2,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});
 dest_dir=({    PATH+"vulcano5", "north",
	        PATH+"vulcano10","east",
		PATH+"vulcano13","south" 
	   });
}
 ::reset(arg);  
}

