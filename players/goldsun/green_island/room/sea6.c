inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "sea7",   "northwest",
	     PATH + "coast5", "west",
	     PATH + "coast1", "south",
	     PATH + "sea1",   "southeast" });
}


