inherit "/players/goldsun/7-islands/sapphire/room/genRiver";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,1,"vuri","players/goldsun/7-islands/sapphire/monster/f_vuri",0,
              2,3,"eel","players/goldsun/7-islands/sapphire/monster/eel",0,
	      3,1,"beaver","players/goldsun/7-islands/sapphire/monster/beaver",0});
 dest_dir=({ PATH+"river4", "north",
	     PATH+"river3", "east",
	     PATH+"river7", "south",
	     PATH+"river5", "west"
	   });
 }
 ::reset(arg);
}
