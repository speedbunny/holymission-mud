inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast3",   "north",
	     PATH + "sea5",     "west",
	     PATH + "sea3",     "east" });
}


