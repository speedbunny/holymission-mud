inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,2,"trout","players/goldsun/7-islands/sapphire/monster/trout",0,
	      2,1,"crayfish","players/goldsun/7-islands/sapphire/monster/crayfish",0});
 dest_dir=({ PATH+"coast4", "north",
	     PATH+"coast5", "east",
	     PATH+"river8", "south",
	     PATH+"coast3", "west"
	   });
 }
 ::reset(arg);
}
