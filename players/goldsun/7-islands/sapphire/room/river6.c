inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,2,"beaver","players/goldsun/7-islands/sapphire/monster/beaver",0,
              2,4,"eel","players/goldsun/7-islands/sapphire/monster/eel",0});
 dest_dir=({ PATH+"river5", "north",
	     PATH+"coast2", "northwest",
	     PATH+"river1", "southeast"
	   });
 }
 ::reset(arg);
}
