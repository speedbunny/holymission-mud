inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"crab","players/goldsun/7-islands/emerald/monster/crab",0});
 dest_dir=({ PATH+"coast9",  "north",
	     PATH+"coast1",  "southeast"
	   });
 }
 ::reset(arg);
}
