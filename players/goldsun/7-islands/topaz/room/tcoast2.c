inherit "/players/goldsun/7-islands/topaz/room/genCoast";
#define PATH "players/goldsun/7-islands/topaz/room/"

void reset(int arg){
 if (!arg){
  dest_dir=({ PATH+"coast3", "east",
	      PATH+"coast1", "west"
	   });

 }
 ::reset(arg);
}

