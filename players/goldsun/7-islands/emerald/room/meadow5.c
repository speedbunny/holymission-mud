inherit "/players/goldsun/7-islands/emerald/room/genMeadow";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"toad","players/goldsun/7-islands/emerald/monster/toad",0});
 dest_dir=({ PATH+"coast6", "north",
	     PATH+"meadow6","west",
	     PATH+"meadow4","south",
	     PATH+"coast5", "east"
	   });
 }
 ::reset(arg);
}
