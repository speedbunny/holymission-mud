inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,5,"crab","players/goldsun/7-islands/emerald/monster/crab",0});
 dest_dir=({ PATH+"coast7",  "northeast",
	     PATH+"meadow6", "east",
	     PATH+"meadow1", "southeast",
	     PATH+"coast9",  "south"
	   });
 }
 ::reset(arg);
}
