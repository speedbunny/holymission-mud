inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 dest_dir=({ PATH+"coast5", "northwest",
	     PATH+"river3", "west",
	     PATH+"river2", "southwest",
	     PATH+"coast7", "south"
	   });
 }
 ::reset(arg);
}
