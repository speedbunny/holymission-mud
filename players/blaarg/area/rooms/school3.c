#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="First Floor Hallway",
	long_desc=
		"This is the end of the first floor hallway. There\n"+
		"are classrooms to the east, and windows looking out\n"+
		"on the west.\n";
	dest_dir=({
		 AROOMS+"school2","south",
		 AROOMS+"school6","east",
		 });
	items=({ 
	  "hall","The hall is freshly cleaned",
	  "doors","The doors are marked with different teacher's names",
	  "windows","The windows look out onto the village road. Across\n"+    
		     "the street you see a sign saying <<Uykio's Shop>>",
	      });
	smell = "This place smells of chalkdust";
	::reset(arg);
	replace_program("room/room");
}