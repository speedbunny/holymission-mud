inherit "/players/goldsun/7-islands/sapphire/room/genCoast";
#define PATH "players/goldsun/7-islands/sapphire/room/"

reset(arg){
 if (!arg){
 clone_list=({1,4,"turtle","players/goldsun/7-islands/sapphire/monster/turtle",0});
 dest_dir=({ PATH+"coast10","northwest",
	     PATH"+river1", "north",
	     PATH+"coast8", "northeast"
	   });
 }
 ::reset(arg);
}
