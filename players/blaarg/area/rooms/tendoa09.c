#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,5,"whitebelt",MOB+"whitebelt",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room--Northwestern Area",
	long_desc=
	  "This is the northwestern area of the practice room. The\n"+
	  "floor is padded by mats, and mirrors run the length of\n"+
	  "the walls. There are some students practicing their kata.\n"; 
	dest_dir=({
	  AROOMS+"tendoa10","west",
	  AROOMS+"tendoa20","south",
	  AROOMS+"tendoa19","southeast",
	  AROOMS+"tendoa08","east",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}