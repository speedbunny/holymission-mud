inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Gos Sun Avenue";
 dest_dir=({ PATH + "road8", "north",
  	     PATH + "road5", "east",
	     PATH + "wall15", "southwest" });
}


