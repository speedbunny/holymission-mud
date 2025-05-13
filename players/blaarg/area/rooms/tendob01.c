#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Stairs--Floor II",
	long_desc=
	    "This staircase leads up to the third floor, and down to the\n"+ 
	    "first. To the North is the east central area of the practice\n"+ 
	    "room, and to the West is the south central area of the practice\n"+ 
	    "room.\n";
	dest_dir=({
	    AROOMS+"tendob08","west",
	    AROOMS+"tendoc01","up",
	    AROOMS+"tendob02","north",
	    AROOMS+"tendoa03","down",
		 });
	items=({ 
		"stairs","The stairs are well-worn",
	      });
	smell = "The staircase smells dusty";
	::reset(arg);
	replace_program("room/room");
}