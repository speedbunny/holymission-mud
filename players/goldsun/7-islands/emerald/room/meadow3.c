inherit "/players/goldsun/7-islands/emerald/room/genMeadow";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,2,"mouse","players/goldsun/7-islands/emerald/monster/mouse",0});
 dest_dir=({ PATH+"meadow4", "north",
	     PATH+"coast2",  "south"
	   });
 }
 ::reset(arg);
}
