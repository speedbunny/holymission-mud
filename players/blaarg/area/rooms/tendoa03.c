#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Stairs--Floor I",
	long_desc=
	    "This staircase leads up to the second floor. To the North\n"+
	    "is the southern area of the east dressing room, and to the\n"+
	    "West is the Parlour.\n";
	dest_dir=({
	    AROOMS+"tendoa02","west",
	    AROOMS+"tendob01","up",
	    AROOMS+"tendoa04","north",
		 });
	items=({ 
		"stairs","The stairs are worn but still sturdy",
	      });
	smell = "The staircase smells dusty";
	::reset(arg);
	replace_program("room/room");
}