inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 dest_dir=({ PATH+"coast3", "northeast",
 	     PATH+"river5", "east",
	     PATH+"river6", "southeast",
	     PATH+"coast1", "south"
	   });
 }
 ::reset(arg);
}
