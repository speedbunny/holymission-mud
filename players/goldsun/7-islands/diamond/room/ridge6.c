inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  clone_list=({1,1,"frost","/players/goldsun/7-islands/diamond/monster/frost",0});
  dest_dir=({ PATH+"ridge5", "northwest",
	      PATH+"inland13","west",
	      PATH+"ridge7", "southwest"
            });
	    

 }
 ::reset(arg);
}
