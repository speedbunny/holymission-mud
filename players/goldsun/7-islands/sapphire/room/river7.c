inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,2,"trout","players/goldsun/7-islands/sapphire/monster/trout",0,
              2,1,"eel","players/goldsun/7-islands/sapphire/monster/eel",0});
 dest_dir=({ PATH+"river8", "north",
	     PATH+"river1", "south"
	   });
 }
 ::reset(arg);
}
