inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast2",   "north",
	     PATH + "sea4",     "west",
	     PATH + "sea2",     "northeast" });
}


