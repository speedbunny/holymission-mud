inherit "/players/goldsun/green_island/room/genCoast";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "meadow1", "north",
	     PATH + "meadow2", "northwest",
	     PATH + "coast3",  "west",
	     PATH + "coast1"  ,"northeast" });
}


