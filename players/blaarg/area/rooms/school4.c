#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="School Hallway",
	long_desc=
		"This hallway leads to the gymnasium. On the left\n"+
		"and right are walls.\n";
	dest_dir=({
		 AROOMS+"gym","east",
		 AROOMS+"school1","west",
		 });
	items=({ 
	  "hall","The hall is freshly cleaned",
	  "walls","The walls are painted white",
	      });
	smell = "This place smells of chalkdust";
	::reset(arg);
	replace_program("room/room");
}