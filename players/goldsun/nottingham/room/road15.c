inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Victory Street";
 dest_dir=({ PATH + "road13", "north",
	     PATH + "road2"  , "south" });
}


