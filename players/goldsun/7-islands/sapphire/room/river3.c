inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"eagle","players/goldsun/7-islands/sapphire/monster/eagle",0,
              2,4,"eel","players/goldsun/7-islands/sapphire/monster/eel",0});
 dest_dir=({ PATH+"coast5", "north",
	     PATH+"coast6", "east",
	     PATH+"river2", "south",
	     PATH+"river8", "west"
	   });
 }
 ::reset(arg);
}
