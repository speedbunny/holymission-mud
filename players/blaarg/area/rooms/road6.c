#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="North Road",
	long_desc=
		"The road is getting closer and closer to the dojo.\n"+
		"To the west is Shampoo's restaurant, and to the east\n"+
		"is the front wall of the school.\n";
	dest_dir=({
		AROOMS+"road5", "south",
		AROOMS+"road7", "north",
		AROOMS+"shshop1", "west",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "restaurant","There is a sign on the door",
	    "school","A quaint little school beckons you to enter",
	    "sign","Welcome to Shampoo's House of Pancakes",
	    "dojo","The dojo is looming to the North."
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}



