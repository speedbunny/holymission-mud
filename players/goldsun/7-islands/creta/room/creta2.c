inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ PATH+"creta1", "north",
	     PATH+"creta5", "east",   
	     PATH+"creta3", "south"
	   });
  
}
