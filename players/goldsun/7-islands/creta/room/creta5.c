inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
 if (arg) return;
 
 dest_dir=({ PATH+"creta1", "northwest",
	     PATH+"creta2", "west",
	     PATH+"creta6", "south",
	     PATH+"creta9", "southeast",
             PATH+"creta8", "east"
	   });
  
}
