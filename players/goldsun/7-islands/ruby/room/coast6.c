inherit "/players/goldsun/7-islands/ruby/room/genCoast";
#define PATH "players/goldsun/7-islands/ruby/room/"

void reset(int arg){
 if (!arg){
 clone_list=({1,random(3),"coast_monster","players/goldsun/7-islands/ruby/monster/coast_monster",0});
 dest_dir=({ PATH+"coast5","north",
	     PATH+"coast7","south"
	   });
  
 }
 ::reset(arg);
}
