#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="School Entrance",
	long_desc=
		"This is where Ranma and his friends go to school.\n"+
		"There are hallways pointing east and north, and a\n"+ 
		"staircase leading upward.\n";
	dest_dir=({
		 AROOMS+"road5","west",
		 AROOMS+"school2","north",
		 AROOMS+"school4","east",
		 AROOMS+"school7","up",
		 });
	items=({ 
	  "hall","The hall is freshly cleaned",
	  "doors","The doors are marked with different teacher's names",
	  "stairs","The stairs lead to the second story of the school",
	      });
	smell = "This place smells of chalkdust";
	::reset(arg);
	replace_program("room/room");
}



