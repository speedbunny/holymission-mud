inherit "players/goldsun/7-islands/diamond/room/genRidge";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg)
{
 
 if (!arg)
 {
  dest_dir=({ PATH+"ridge7", "northeast",
	      PATH+"inland12","north",
	      PATH+"ridge9", "southwest"
            });
	    

 }
 ::reset(arg);
}
