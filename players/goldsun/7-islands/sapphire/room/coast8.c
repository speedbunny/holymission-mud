inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 dest_dir=({ PATH+"coast7", "northeast",
	     PATH+"coast9", "southwest"
	   });
 }
 ::reset(arg);
}
