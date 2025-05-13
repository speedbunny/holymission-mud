#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Stairs--Floor III",
	long_desc=
	    "This staircase leads down to the second floor. There is a\n"+
	    "room to the North.\n";
	dest_dir=({
	    AROOMS+"tendoc02","north",
	    AROOMS+"tendob01","down",
		 });
	items=({ 
		"stairs","The stairs are well-worn",
	      });
	smell = "The staircase smells dusty";
	::reset(arg);
	replace_program("room/room");
}