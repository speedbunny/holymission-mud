inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Castle Road";
 dest_dir=({ PATH + "road2", "west",
	     PATH + "shop" , "north",       
	     PATH + "gates", "east",
	     PATH + "pub"  , "south" });
}


