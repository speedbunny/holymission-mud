inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  
  dest_dir=({ PATH+"pass", "northwest",
	      PATH+"inland1","north",
	      PATH+"ridge10","southeast"
            });
	    

 }
 ::reset(arg);
}
