#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"blackbelt",MOB+"blakbelt",0,
		2,1,"brownbelt",MOB+"bronbelt",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room, Floor II--Northeastern Area",
	long_desc=
	  "This is the northeastern area of the practice room on the\n"+
	  "second floor. The floor is padded by mats, and mirrors run\n"+ 
	  "the length of the walls. There are some students practicing\n"+ 
	  "their kata.\n"; 
	dest_dir=({
	  AROOMS+"tendob04","west",
	  AROOMS+"tendob03","south",
	  AROOMS+"tendob09","southwest",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}