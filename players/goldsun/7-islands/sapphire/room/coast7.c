inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 dest_dir=({ PATH+"coast6", "north",
	     PATH+"coast8", "southwest"
	   });
 }
 ::reset(arg);
}
