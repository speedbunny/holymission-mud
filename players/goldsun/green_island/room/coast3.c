inherit "/players/goldsun/green_island/room/genCoast";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
 ::reset(arg);

if (arg) return;

 dest_dir=({ PATH + "meadow2","north",
	     PATH + "meadow3","northwest",
	     PATH + "coast4", "west",
	     PATH + "coast2", "east",
	     PATH + "meadow1","northeast" });
}


