#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="North Road",
	long_desc=
		"The road has now led into the Village proper.  To the\n"+
		"East is a school, and to the West is a small shop.\n";
	dest_dir=({
		AROOMS+"road4", "south",
		AROOMS+"road6", "north",
		AROOMS+"spshop", "west",
		AROOMS+"school1", "east",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "shop","There is a sign on the door",
	    "school","A quaint little school beckons you to enter",
	    "sign","The sign reads: Welcome to the special shop",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}



