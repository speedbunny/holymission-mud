inherit "/players/goldsun/7-islands/emerald/room/genMeadow";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,7,"ant","players/goldsun/7-islands/emerald/monster/ant",0});
 dest_dir=({ PATH+"meadow6", "north",
	     PATH+"coast8",  "northwest",
	     PATH+"meadow2", "south",
	     PATH+"meadow4", "east"
	   });
 }
 ::reset(arg);
}
