inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"crab","players/goldsun/7-islands/emerald/monster/crab",0});
 dest_dir=({ PATH+"coast5", "north",
	     PATH+"coast3", "south",  
	   });
 }  
 ::reset(arg);
}
