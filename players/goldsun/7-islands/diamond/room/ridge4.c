inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  dest_dir=({ PATH+"ridge3", "northwest",
	      PATH+"inland5","west",
	      PATH+"ridge5", "southeast"
            });
	    

 }
 ::reset(arg);
}
