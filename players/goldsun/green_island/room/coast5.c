inherit "/players/goldsun/green_island/room/genCoast";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast6", "northwest",
	     PATH + "meadow5","west",
	     PATH + "meadow2","southwest",
	     PATH + "meadow1","south",
	     PATH + "coast1"  , "southeast" });
}


