inherit "/players/goldsun/7-islands/topaz/room/genCoast";
#define PATH "players/goldsun/7-islands/topaz/room/"

void reset(int arg){
 if (!arg){
  clone_list=({1,3,"turtle","players/goldsun/7-islands/topaz/monster/turtle",0,
               2,5,"crab","players/goldsun/7-islands/topaz/monster/crab",0});
  dest_dir=({ PATH+"coast4", "east",
	      PATH+"coast2", "west"
	   });

 }
 ::reset(arg);
}

