inherit "/players/goldsun/7-islands/creta/room/creta9";
#define PATH "/players/goldsun/7-islands/creta/room/"

void reset(int arg){
 ::reset(arg);
if (!arg){
 dest_dir=({ PATH+"creta9", "north",
	     PATH+"creta12","east",
	     PATH+"creta13","southeast",
	     PATH+"creta7", "west"
	   });

 }
}

