inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "sea10",   "southwest",
	     PATH + "coast7", "south",
	     PATH + "sea8",   "east" });
}


