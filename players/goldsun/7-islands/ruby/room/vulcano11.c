inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,4,"vmona","players/goldsun/7-islands/ruby/monster/vulc_monster_a",0,
          2,1,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});
 dest_dir=({    PATH+"vulcano7", "north",
	        PATH+"vulcano12","east",
		PATH+"vulcano15","south",
		PATH+"vulcano10","west"
	   });
}
 ::reset(arg);  
}

