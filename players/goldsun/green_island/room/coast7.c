inherit "/players/goldsun/green_island/room/genCoast";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "hill4", "southwest",
	     PATH + "meadow4","south",
	     PATH + "meadow5","southeast",
	     PATH + "coast6"  , "east" });
}


