#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Intersection",
	long_desc=
	    "The road has come to an intersection. Directly to the\n"+
	    "North is the Tendo <<All-or-Nothing>> Dojo, and another\n"+
	    "road leads East and West.\n";
	dest_dir=({
	    AROOMS+"road7", "south",
	    AROOMS+"tendoa01", "north",
	    AROOMS+"roadb1", "west",
	    AROOMS+"roada1", "east",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "dojo","The dojo is straight North",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}

