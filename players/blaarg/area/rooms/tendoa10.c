#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo West Dressing Room--Northern Area",
	long_desc=
	  "This is the northern area of the west dressing room. There\n"+
	  "are some storage boxes here, and a bench runs the length of\n"+
	  "the room. To the South is the central area of the dressing\n"+
	  "room, and to the East is the northwestern area of the practice\n"+ 
	  "room.\n";
	dest_dir=({
	  AROOMS+"tendoa09","east",
	  AROOMS+"tendoa11","south",
		 });
	items=({ 
	  "boxes","The boxes hold the clothes of the students",
	  "bench","The bench, made of pine, shows a lot of wear",
	      });
	smell = "The dressing room smells musty";
	::reset(arg);
	replace_program("room/room");
}
