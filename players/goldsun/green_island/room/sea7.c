inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "sea8",   "northwest",
	     PATH + "coast6", "west",
	     PATH + "coast5", "south",
	     PATH + "sea6",   "southeast" });
}


