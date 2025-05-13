#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,6,"whitebelt",MOB+"whitebelt",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room--North Central Area",
	long_desc=
	  "This is the north central area of the practice room. The\n"+
	  "floor is padded by mats, and mirrors run the length of\n"+
	  "the walls. There are some students here practicing their kata.\n";  
	dest_dir=({
	  AROOMS+"tendoa09","west",
	  AROOMS+"tendoa19","south",
	  AROOMS+"tendoa20","southwest",
	  AROOMS+"tendoa18","southeast",
	  AROOMS+"tendoa07","east",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}