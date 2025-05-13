#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="East-West road",
	long_desc=
		"The East-West road runs along the north part of the\n"+
		"village. To the north is a side street, and to the\n"+
		"south is Moose's house.\n";
	dest_dir=({
		AROOMS+"roadb4", "west",
		AROOMS+"roadb2", "east",
		AROOMS+"mhouse", "south",
		AROOMS+"roadc1","north",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "street","The side street runs next to the dojo",
	    "house","Moose's house is tiny and a bit dilapidated",
	    "dojo","The dojo looms to the north",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}


