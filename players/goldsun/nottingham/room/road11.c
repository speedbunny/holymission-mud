inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 short_desc="Gos Sun Avenue";
 dest_dir=({ PATH + "wall9", "northwest",
	     PATH + "road12", "east",
	     PATH + "road10"  , "south" });
}


