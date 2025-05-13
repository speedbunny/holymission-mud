#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,6,"teacher",MOB+"teacher",0,
		-1,1,"ruler",WEAPON+"ruler",0,
	});
	set_light(1);
	short_desc="Classroom",
	long_desc=
	    "You have stumbled into what appears to be the faculty\n"+
	    "breakroom. There are a few teachers sitting around,\n"+
	    "drinking coffee.\n";
	dest_dir=({
		AROOMS+"school9","west",
		 });
	items=({ 

	      });
	smell = "This place is a bit dusty";
    	::reset(arg);
	replace_program("room/room");
}