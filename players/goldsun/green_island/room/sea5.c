inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast4",   "north",
	     PATH + "sea14",    "west",
	     PATH + "sea4",     "east" });
}


