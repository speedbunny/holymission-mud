inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  
  dest_dir=({ PATH+"ridge4", "northwest",
	      PATH+"inland13","south",
	      PATH+"ridge6", "southeast"
            });
	    

 }
 ::reset(arg);
}
