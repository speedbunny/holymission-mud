inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Gos Sun Avenue";
 dest_dir=({ PATH + "road10", "north",
	     PATH + "road16", "west",
	     PATH + "road8"  , "south" });
}


