inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ PATH+"creta15","north",
	     PATH+"creta12","west",
	     PATH+"creta13","southwest",
	     PATH+"creta17","northeast"
	   });
  
}
