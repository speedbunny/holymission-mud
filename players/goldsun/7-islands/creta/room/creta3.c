inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
 if (arg) return;

 dest_dir=({ PATH+"creta2", "north",
	     PATH+"creta6", "east",
	     PATH+"creta4", "south"
	   });
  
}
