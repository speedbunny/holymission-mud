inherit "/players/goldsun/green_island/room/genCoast";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "coast7", "west",
	     PATH + "meadow4","southwest",
	     PATH + "meadow5","south",
	     PATH + "coast5"  , "southeast" });
}


