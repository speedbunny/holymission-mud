#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,2,"brownbelt",MOB+"bronbelt",0,
		2,3,"blackbelt",MOB+"blakbelt",0,
	});	
	set_light(1);
	short_desc="Tendo Practice Room, Floor II--North Central Area",
	long_desc=
	  "This is the north central area of the practice room on the\n"+
	  "second floor. The floor is padded by mats, and mirrors run\n"+ 
	  "the length of the walls. There are some students practicing\n"+ 
	  "their kata.\n"; 
	dest_dir=({
	  AROOMS+"tendob05","west",
	  AROOMS+"tendob03","east",
	  AROOMS+"tendob09","south",
	  AROOMS+"tendob06","southwest",
	  AROOMS+"tendob02","southeast",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}