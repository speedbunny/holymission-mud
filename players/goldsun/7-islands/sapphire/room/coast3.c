inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,3,"seagull","players/goldsun/7-islands/sapphire/monster/seagull",0});

 dest_dir=({ PATH+"coast4", "northeast",
	     PATH+"river4", "east",
	     PATH+"river5", "south",
	     PATH+"coast10","southwest"
	   });
 }
 ::reset(arg);
}
