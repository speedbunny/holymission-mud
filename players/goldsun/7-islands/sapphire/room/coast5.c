inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,4,"seagull","players/goldsun/7-islands/sapphire/monster/seagull",0});
 dest_dir=({ PATH+"coast4", "northwest",
	     PATH+"river4", "west",
	     PATH+"river3", "south",
	     PATH+"coast6", "southeast"
	   });
 }
 ::reset(arg);
}
