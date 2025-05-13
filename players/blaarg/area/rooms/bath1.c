#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
    	set_light(1);
	short_desc="Public Bath -- Entry",
	long_desc=
	    "This is the entry room of the Bath. There is a desk, a lantern, "+
	    "and doorways leading north and east from here.\n";
	dest_dir=({
		AROOMS+"bath4","north",
		AROOMS+"bath2","east",
		AROOMS+"roada4","south",
		 });
	items=({
	    "desk","The desk have a lot of papers on it",
	    "lantern","The lantern lights the entryway at night",
	    "doorways","The doorways lead to the bath proper", 
	      });
	smell = "The entry smells of Sandalwood";
	::reset(arg);
    	replace_program("room/room");
}

