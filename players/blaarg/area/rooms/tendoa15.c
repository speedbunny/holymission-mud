#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,4,"whitebelt",MOB+"whitebelt",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room--Southwestern Area",
	long_desc=
	  "This is the Southwestern area of the practice room. The\n"+
	  "floor is padded by mats, and mirrors run the length of\n"+
	  "the walls. There are some students practicing their kata.\n"; 
	dest_dir=({
	  AROOMS+"tendoa12","west",
	  AROOMS+"tendoa20","north",
	  AROOMS+"tendoa19","northeast",
	  AROOMS+"tendoa16","east",
	  AROOMS+"tendoa14","south",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}