inherit "/players/goldsun/7-islands/emerald/room/genCoast";
#define PATH "players/goldsun/7-islands/emerald/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ PATH+"coast10", "northwest",
	     PATH+"meadow2", "north",
	     PATH+"coast2",  "east",  
	   });
  
}
