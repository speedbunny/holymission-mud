inherit "/players/goldsun/7-islands/emerald/room/genMeadow";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,3,"bunny","players/goldsun/7-islands/emerald/monster/bunny",0});
 dest_dir=({ PATH+"meadow1", "north",
	     PATH+"coast1",  "south"
	   });
 }
 ::reset(arg);
}
