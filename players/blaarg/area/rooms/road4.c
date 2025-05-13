#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="North Road",
	long_desc=
		"This is the road leading to the village. To the East\n"+
		"is a little park, and to the West is a small shrine.\n";
	dest_dir=({
		AROOMS+"road3", "south",
		AROOMS+"road5", "north",
		AROOMS+"cshrine", "west",
		AROOMS+"park1", "east",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "park","The park is small, but pretty",
	    "shrine","The shrine is small, in honor of Shinto",
	    "village", "The small village starts to the north, "+
			 "after the forest ends.\n",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}
