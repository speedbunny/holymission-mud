#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,3,"brownbelt",MOB+"bronbelt",0,
		2,2,"blackbelt",MOB+"blakbelt",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room, Floor II--South Central Area",
	long_desc=
	  "This is the south central area of the practice room on the\n"+
	  "second floor. The floor is padded by mats, and mirrors run\n"+ 
	  "the length of the walls. There are some students practicing\n"+ 
	  "their kata.\n"; 
	dest_dir=({
	  AROOMS+"tendob01","east",
	  AROOMS+"tendob07","west",
	  AROOMS+"tendob09","north",
	  AROOMS+"tendob02","northeast",
	  AROOMS+"tendob06","northwest",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}