inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){
 ::reset(arg);

if (arg) return;
 short_desc="Gal Perceval Street";
 dest_dir=({ PATH + "road11", "west",
	     PATH + "herb_shop","north",
	     PATH + "road13"  , "east" });
}


