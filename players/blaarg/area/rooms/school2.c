#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="First Floor Hallway",
	long_desc=
		"This is the first floor hallway. There are classrooms to\n"+
		"the east, and windows looking out on the west.\n";
	dest_dir=({
		 AROOMS+"school3","north",
		 AROOMS+"school5","east",
		 AROOMS+"school1","south",
		 });
	items=({ 
	  "hall","The hall is freshly cleaned",
	  "doors","The doors are marked with different teacher's names",
	  "windows","The windows look out onto the village road. Across\n"+    
		    "the street you see a sign saying <<Shampoo's Shop>>",
	      });
	smell = "This place smells of chalkdust";
	::reset(arg);
	replace_program("room/room");
}