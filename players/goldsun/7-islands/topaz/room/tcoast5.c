inherit "/players/goldsun/7-islands/topaz/room/genCoast";
#define PATH "players/goldsun/7-islands/topaz/room/"

void reset(int arg){
 if (!arg){
  clone_list=({1,1,"crab","players/goldsun/7-islands/topaz/monster/crab",0});

  dest_dir=({ PATH+"coast6", "northeast",
	      PATH+"coast4", "southwest"
	   });

 }
 ::reset(arg);
}

