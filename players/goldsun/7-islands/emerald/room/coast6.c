inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 dest_dir=({ PATH+"coast7",  "west",
	     PATH+"meadow5", "south",
	     PATH+"coast5",  "southeast"
	   });
 }
 ::reset(arg);
}
