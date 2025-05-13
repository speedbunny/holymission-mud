#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,2,"sensai",MOB+"sensai",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room, Floor II--Central Area",
	long_desc=
	  "This is the central area of the practice room on the second\n"+
	  "floor. The floor is padded by mats. There are two sensai here,\n"+ 
	  "teaching their students.\n";
	dest_dir=({
	  AROOMS+"tendob01","southeast",
	  AROOMS+"tendob02","east",
	  AROOMS+"tendob03","northeast",
	  AROOMS+"tendob04","north",
	  AROOMS+"tendob05","northwest",
	  AROOMS+"tendob06","west",
	  AROOMS+"tendob07","southwest",
	  AROOMS+"tendob08","south",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}