inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast1",   "north",
	     PATH + "coast2",   "west",
	     PATH + "sea3",     "southwest",
	     PATH + "sea1",     "northeast" });
}


