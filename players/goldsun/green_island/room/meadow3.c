inherit "/players/goldsun/green_island/room/genMeadow";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "meadow4",  "north",
	     PATH + "hill4",    "northwest",
	     PATH + "hill3",    "west",
	     PATH + "hill1",    "southwest",
	     PATH + "coast4",   "south",
	     PATH + "coast3",   "southeast",
	     PATH + "meadow2",   "east",
	     PATH + "meadow5",   "northeast"});
}


