inherit "/players/goldsun/green_island/room/genSea";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "sea6",   "northwest",
	     PATH + "coast1", "west",
	     PATH + "sea2",   "southwest" });
}


