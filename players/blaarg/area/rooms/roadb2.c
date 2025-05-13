#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="East-West road",
	long_desc=
		"The East-West road runs along the north part of the\n"+
		"village. To the north is the southern wall of the Tendo\n"+
		"Dojo, and to the south is Uykio's house.\n";
	dest_dir=({
		AROOMS+"roadb3", "west",
		AROOMS+"roadb1", "east",
		AROOMS+"uhouse", "south",
		 });
	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "dojo","The dojo looms to the north",
	    "house","Ukyio's house is well-kept and beautifully landscaped",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
	replace_program("room/room");
}
