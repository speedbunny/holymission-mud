inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,4,"crab","players/goldsun/7-islands/sapphire/monster/crab",0});
 dest_dir=({ PATH+"coast1", "northwest",
	     PATH+"coast9", "southeast"
	   });
 }
 ::reset(arg);
}
