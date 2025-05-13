#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Village Park",
	long_desc=
		"This is the Village Park. The path that leads through\n"+
		"the park is lined with beautiful flowers, and stretches\n"+
		"to the east. The south is blocked by a thick forest.\n";
	dest_dir=({
		AROOMS+"road4", "west",
		AROOMS+"park2", "east",
		 });
	items=({ 
	    "air","The air clears as you enter the park",
	    "flowers","The flowers look and smell wonderful",
	    "grass","The grass was freshly cut, and sticks to your feet",
	      });
	smell = "This place smells of freshly cut grass and flowers";
	::reset(arg);
	replace_program("room/room");
}


