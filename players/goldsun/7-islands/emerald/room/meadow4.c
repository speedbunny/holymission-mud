inherit "/players/goldsun/7-islands/emerald/room/genMeadow";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"swarm","players/goldsun/7-islands/emerald/monster/gnat",0});
 dest_dir=({ PATH+"meadow5", "north",
	     PATH+"coast5",  "northeast",
	     PATH+"meadow3", "south",
	     PATH+"meadow1", "west"
	   });
 }
 ::reset(arg);
}
