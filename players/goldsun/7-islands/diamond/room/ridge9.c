inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  clone_list=({1,1,"frost","/players/goldsun/7-islands/diamond/monster/frost",0});  
  dest_dir=({ PATH+"ridge8", "northeast",
	      PATH+"inland9","north",
	      PATH+"ridge10","northwest"
            });
	    

 }
 ::reset(arg);
}
