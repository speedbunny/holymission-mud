inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,2,"eel","players/goldsun/7-islands/sapphire/monster/eel",0});
 dest_dir=({ PATH+"river7", "north",
	     PATH+"river2", "northeast",
	     PATH+"coast9", "south",
	     PATH+"river6", "northwest"
	   });
 }
 ::reset(arg);
}
