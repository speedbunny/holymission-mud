#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Female dressing area",
	long_desc=
		"The female dressing room is a quaint room painted "+
		"pink, with small storage boxes stacked against the "+
		"walls for the female bathers to store their clothing in.\n";
	dest_dir=({
		AROOMS+"bath4","south",
		 });
	items=({
	    "walls","The walls are painted pink",
	    "boxes","The boxes are made of bamboo. You can't open them",
	      });
	smell = "The dressing room smells sweet, as if scented";
	::reset(arg);
	replace_program("room/room");
}

