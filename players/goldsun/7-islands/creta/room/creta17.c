inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ PATH+"creta15", "west",
	     PATH+"creta16", "southwest",
	     PATH+"creta18", "east"
	   });
  
}
