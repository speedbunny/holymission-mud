inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Coal Circus";
 dest_dir=({ PATH + "wall11", "northwest",
     	     PATH + "road18", "west",
	     PATH + "wall13", "southwest",
	     PATH + "road16"  , "east" });
}


