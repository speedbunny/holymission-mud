inherit "/players/goldsun/7-islands/ruby/room/genVulcano";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
if (!arg){
 clone_list=({1,6,"vmon","players/goldsun/7-islands/ruby/monster/vulc_monster",0});
 dest_dir=({    PATH+"vulcano4","north",
                PATH+"vulcano7", "west",
		PATH+"vulcano12","south" 
	   });
}
 ::reset(arg);  
}

