inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"duckling","players/goldsun/7-islands/emerald/monster/duckling",0});
 dest_dir=({ PATH+"coast6",  "east",
	     PATH+"meadow6", "south",
	     PATH+"coast8",  "southwest"
	   });
 }
 ::reset(arg);
}
