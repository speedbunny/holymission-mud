inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"vmona","players/goldsun/7-islands/ruby/monster/vulc_monster_a",0,
          2,1,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});

 dest_dir=({    PATH+"vulcano6", "north",
	        PATH+"vulcano11","east",
		PATH+"vulcano14","south",
		PATH+"vulcano9", "west",
	   });
}
 ::reset(arg);  
}

