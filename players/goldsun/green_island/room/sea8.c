inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "sea9",   "west",
	     PATH + "coast6", "south",
	     PATH + "sea7",   "southeast" });
}


