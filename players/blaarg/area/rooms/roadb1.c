#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="East-West road",
	long_desc=
		"The East-West road runs along the north part of the\n"+
		"village. To the north is the southern wall of the Tendo\n"+
		"Dojo, and to the south is Uykio's shop.\n";
	dest_dir=({
		AROOMS+"roadb2", "west",
		AROOMS+"road8", "east",
		AROOMS+"ushop","south",
	 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "shop","There is a sign on the door",
	    "school","A quaint little school beckons you to enter",
	    "sign","Welcome to Uykio's Shop",
	    "dojo","The dojo looms to the north",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}