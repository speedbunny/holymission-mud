inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  
  dest_dir=({ PATH+"ridge3", "northeast",
	      PATH+"inland5", "east",
	      PATH+"ridge1", "southwest"
            });
	    

 }
 ::reset(arg);
}
