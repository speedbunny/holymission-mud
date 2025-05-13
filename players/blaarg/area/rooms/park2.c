#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Village Park",
	long_desc=
		"The path leads through the most beautiful parts of the\n"+
		"park. It seems to continue for a short way west. To the\n"+
		"North, the school's walls block your path. The south is\n"+
		"blocked by a thick forest.\n";
	dest_dir=({
		AROOMS+"park1", "west",
		AROOMS+"park3", "east",
	});
	items=({ 
	    "air","The air is beautiful, filled with fresh scents",
	    "flowers","The flowers look and smell wonderful",
	    "grass","The grass was freshly cut, and sticks to your feet",
	    "forest", "The forest is too thick to see through",
	    "walls","The walls are too high and sheer to climb",  
	});
	smell = "This place smells of freshly cut grass and flowers";
	::reset(arg);
	replace_program("room/room");
}