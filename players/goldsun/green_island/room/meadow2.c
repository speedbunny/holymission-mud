inherit "/players/goldsun/green_island/room/genMeadow";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "meadow5", "north",
	     PATH + "meadow4", "northwest",
	     PATH + "meadow3", "west",
	     PATH + "coast4"  , "southwest",
	     PATH + "coast3",   "south",
	     PATH + "coast2",   "southeast",
	     PATH + "meadow1",  "east",
	     PATH + "coast5",   "northeast"});
}


