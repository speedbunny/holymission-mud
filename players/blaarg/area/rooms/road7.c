#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="North Road",
	long_desc=
		"The road is getting closer and closer to the dojo.\n"+
		"To the west is Uykio's shop, and to the east\n"+
		"is the front wall of the school.\n";
	dest_dir=({
		AROOMS+"road6", "south",
		AROOMS+"road8", "north",
		AROOMS+"ushop", "west",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "shop","There is a sign on the door",
	    "school","A quaint little school beckons you to enter",
	    "sign","Welcome to Uykio's Shop",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}




