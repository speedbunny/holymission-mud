inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ PATH+"creta6", "west",
	     PATH+"creta9", "south",
	     PATH+"creta11", "east"
	   });
}
