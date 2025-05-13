#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Village Park",
	long_desc=
		"This path dead-ends at a stone wall. The north is\n"+
		"still blocked by the school's walls, and the south is\n"+
		"blocked by a thick forest.\n";
	dest_dir=({
		AROOMS+"park2", "west",
		 });
	items=({ 
	    "air","The air is beautiful, filled with fresh scents",
	    "flowers","The flowers look and smell wonderful",
	    "grass","The grass was freshly cut, and sticks to your feet",
	    "forest", "The forest is too thick to see through",
	});
	smell = "This place smells of freshly cut grass and flowers";
	::reset(arg);
	replace_program("room/room");
}



