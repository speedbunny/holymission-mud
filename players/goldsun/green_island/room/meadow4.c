inherit "/players/goldsun/green_island/room/genMeadow";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){

if (!arg){
 clone_list=({1,1,"tree","players/goldsun/green_island/obj/ebony_tree",0});
 dest_dir=({ PATH + "coast7",  "north",
	     PATH + "hill4",   "west",
	     PATH + "hill3",   "southwest",
	     PATH + "meadow3", "south",
	     PATH + "meadow2", "southeast",
	     PATH + "meadow5", "east",
	     PATH + "coast6",  "northeast"});
 }
 ::reset(arg);
}


