#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo East Dressing Room--Central Area",
	long_desc=
	  "This is the central area of the east dressing room. There\n"+
	  "are some storage boxes here, and a bench runs the length of\n"+
	  "the room. To the North is the northern area of the dressing\n"+
	  "room, to the South is the southern area of the dressing room,\n"+
	  "and to the West is the east central area of the practice room.\n";
	dest_dir=({
	  AROOMS+"tendoa18","west",
	  AROOMS+"tendoa04","south",
	  AROOMS+"tendoa06","north",
		 });
	items=({ 
	  "boxes","The boxes hold the clothes of the students",
	  "bench","The bench, made of pine, shows a lot of wear",
	      });
	smell = "The dressing room smells musty";
	::reset(arg);
	replace_program("room/room");
}