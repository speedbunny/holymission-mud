inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Victory Street";
 dest_dir=({ PATH + "road14", "northeast",
             PATH + "barracks","east",
	     PATH + "road12", "west",
	     PATH + "road15"  , "south" });
}


