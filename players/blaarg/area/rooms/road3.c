#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="North Road",
	long_desc=
		"This is the road leading to the village. The forest\n"+
		"blocks your view to the East and West.\n";
	dest_dir=({
		AROOMS+"road2", "south",
		AROOMS+"road4", "north",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "forest", "The forest is too thick to see through",
	    "village", "The small village starts to the north, "+
			  "after the forest ends.\n",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}



