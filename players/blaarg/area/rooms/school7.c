#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Second Floor Hallway",
	long_desc=
		"This is the second floor hallway. There are classrooms to "+
		"the east, and windows looking out on the west.\n";
	dest_dir=({
		 AROOMS+"school8","north",
		 AROOMS+"school10","east",
		 AROOMS+"school1","down",
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
