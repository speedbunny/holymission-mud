inherit "/players/goldsun/7-islands/topaz/room/genCoast";
#define PATH "players/goldsun/7-islands/topaz/room/"

void reset(int arg){
 if (!arg){
  dest_dir=({ PATH+"coast7", "northeast",
	      PATH+"coast5", "southwest"
	   });

 }
 ::reset(arg);
}

