inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"lobster","players/goldsun/7-islands/emerald/monster/lobster",0});
 dest_dir=({ PATH+"coast8",  "north",
	     PATH+"coast10", "south"
	   });
 }
 ::reset(arg);
}
