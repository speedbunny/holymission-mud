inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Victory Street";
 dest_dir=({ PATH + "road4", "east",
	     PATH + "road6", "south",
	     PATH + "road7"  , "west" });
}


