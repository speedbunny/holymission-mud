inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,3,"beaver","players/goldsun/7-islands/sapphire/monster/beaver",0});
 dest_dir=({ PATH+"river3", "north",
	     PATH+"coast6", "northeast",
	     PATH+"river1", "southwest"
	   });
 }
 ::reset(arg);
}
