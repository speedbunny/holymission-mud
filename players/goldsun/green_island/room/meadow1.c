inherit "/players/goldsun/green_island/room/genMeadow";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast5",  "north",
	     PATH + "meadow5", "northwest",
	     PATH + "meadow2", "west",
	     PATH + "coast3"  , "southwest",
	     PATH + "coast2",   "south",
	     PATH + "coast1",   "east"});
}


