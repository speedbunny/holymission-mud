inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"crayfish","players/goldsun/7-islands/sapphire/monster/crayfish",0});
 dest_dir=({ PATH+"coast3", "north",
	     PATH+"river8", "east",
	     PATH+"river6", "south",
	     PATH+"coast2", "west"
	   });
 }
 ::reset(arg);
}
