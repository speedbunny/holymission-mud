inherit "/players/goldsun/green_island/room/genCoast";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "meadow3","north",
	     PATH + "hill2",  "northwest",
	     PATH + "hill1",  "west",
	     PATH + "meadow2","northeast",
	     PATH + "coast3" ,"east" });
}


