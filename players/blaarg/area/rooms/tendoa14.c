#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Hall",
	long_desc=
	    "This is a hall in the Tendo All-For-Nothing Dojo.\n"+
	    "To the East is the entry, to the West is the Office,\n"+
	    "and to the North is the southwestern area of the practice\n"+ 
	    "room.\n";
	dest_dir=({
		AROOMS+"tendoa01","east",
		AROOMS+"tendoa13","west",
		AROOMS+"tendoa15","north",
		 });
	items=({ 
	      });
	smell = "The hall smells dusty";
	::reset(arg);
	replace_program("room/room");
}