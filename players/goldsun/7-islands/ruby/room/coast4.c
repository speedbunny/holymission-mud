inherit "/players/goldsun/7-islands/ruby/room/genCoast";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
 if (!arg){
 dest_dir=({ PATH+"coast3","west",
	     PATH+"vulcano4","southwest",
	     PATH+"coast5", "south"
	   });
  
 }
 ::reset(arg);
}
