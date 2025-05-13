#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,9,"whitebelt",MOB+"whitebelt",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room--Southeastern Area",
	long_desc=
	  "This is the Southeastern area of the practice room. The\n"+
	  "floor is padded by mats, and mirrors run the length of\n"+
	  "the walls. There are some students practicing their kata.\n"; 
	dest_dir=({
	  AROOMS+"tendoa16","west",
	  AROOMS+"tendoa18","north",
	  AROOMS+"tendoa19","northwest",
	  AROOMS+"tendoa02","south",
	  AROOMS+"tendoa04","east",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}