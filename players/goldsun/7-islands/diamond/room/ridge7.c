inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  clone_list=({1,2,"frost","/players/goldsun/7-islands/diamond/monster/frost",0});  
  dest_dir=({ PATH+"ridge6", "northeast",
	      PATH+"ridge8", "southwest"
            });
	    

 }
 ::reset(arg);
}
