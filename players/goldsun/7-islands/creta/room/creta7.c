inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ PATH+"creta6", "north",
	     PATH+"creta4", "west",
            PATH+"creta10","east"
	   });
  
}
