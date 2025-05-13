#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Second Floor Hallway",
	long_desc=
		"This is the second floor hallway. There are classrooms\n"+
		"to the east, and windows looking out on the west.\n";
	dest_dir=({
		 AROOMS+"school9","north",
		 AROOMS+"school11","east",
		 AROOMS+"school7","south",
	 });
	items=({ 
	  "hall","The hall is freshly cleaned",
	  "doors","The doors are marked with different teacher's names",
	  "windows","The windows look out onto the village road. It\n"+
		    "seems like it is a long way down",    
	      });
	smell = "This place smells of chalkdust";
	::reset(arg);
	replace_program("room/room");
}