#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
    if(!arg) {
	set_light(1);
	short_desc="Tendo West Dressing Room--Southern Area",
	long_desc=
	    "This is the southern area of the west dressing room. There\n"+
	    "are some storage boxes here, and a bench runs the length of\n"+
	    "the room. To the North is the central area of the dressing\n"+
	    "room, to the South is the office, and to the East is the\n"+
	    "southwestern area of the practice room.\n";
	dest_dir=({
	    AROOMS+"tendoa15","east",
	    AROOMS+"tendoa13","south",
	    AROOMS+"tendoa11","north",
		 });
	items=({ 
	    "boxes","The boxes hold the clothes of the students",
	    "bench","The bench, made of pine, shows a lot of wear",
	      });
	smell = "The dressing room smells musty";
	::reset(arg);
	replace_program("room/room");
}