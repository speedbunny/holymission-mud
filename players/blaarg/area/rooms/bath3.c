#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,2,"bather",MOB+"bather",0,
	});
 	set_light(1);
	short_desc="Public Bath -- Northeastern Bathing Area",
	long_desc=
	  "This is the Northwestern area of the bath. The\n"+
	  "water looks very warm, and mirrors run the length of\n"+
	  "the walls. There are some bathers having a good time.\n"; 
	dest_dir=({
	  AROOMS+"bath6","north",
	  AROOMS+"bath4","west",
	  AROOMS+"bath1","southwest",
	  AROOMS+"bath2","south",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	      });
	smell = "The bath smells like the flowers they scent the water with";
	::reset(arg);
	replace_program("room/room");
}
