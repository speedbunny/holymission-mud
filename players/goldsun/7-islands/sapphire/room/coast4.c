inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 dest_dir=({ PATH+"coast3", "southwest",
	     PATH+"river4", "south",
	     PATH+"coast5", "southeast"
	   });
 }
 ::reset(arg);
}
