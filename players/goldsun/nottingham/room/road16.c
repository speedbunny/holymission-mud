inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"

reset(arg){

if (!arg){
 clone_list=({1,1,"sign","players/goldsun/nottingham/obj/sign",0});
 short_desc="Rotschild Street";
 dest_dir=({ PATH + "road17", "west",
	     PATH + "bank"   , "south",
	     PATH + "road9"  , "east" });

 }
 ::reset(arg);
}

