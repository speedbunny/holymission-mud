inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,3,"lobster","players/goldsun/7-islands/emerald/monster/lobster",0});
 dest_dir=({ PATH+"coast6",  "northwest",
	     PATH+"meadow5", "west",
	     PATH+"meadow4", "southwest",
	     PATH+"coast4",  "south"
	   });
 }
 ::reset(arg);
}
