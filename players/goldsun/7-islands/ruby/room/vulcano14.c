inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"vmona","players/goldsun/7-islands/ruby/monster/vulc_monster_a",0,
          2,6,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});

 dest_dir=({    PATH+"vulcano10","north",
	        PATH+"vulcano15","east",
		PATH+"vulcano13","west" 
	   });
}
 ::reset(arg);  
}

