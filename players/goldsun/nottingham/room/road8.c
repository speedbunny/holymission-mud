inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Gos Sun Avenue";
 dest_dir=({ PATH + "road9", "north",
	     PATH + "smithy", "east",
	     PATH + "road7", "south" });
}


