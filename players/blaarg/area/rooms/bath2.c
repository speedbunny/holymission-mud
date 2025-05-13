#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,2,"bather",MOB+"bather",0,
	});
	set_light(1);
	short_desc="Public Bath -- Southeastern Bathing Area",
	long_desc=
	  "This is the southeastern area of the bath. The "+
	  "water looks very warm, and mirrors run the length of "+
	  "the walls. There are some bathers having a good time.\n"; 
	dest_dir=({
	  AROOMS+"bath3","north",
	  AROOMS+"bath1","west",
	  AROOMS+"bath4","northwest",
	 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "water","The water is clear, and looks warm",
	      });
	smell = "The bath smells like the flowers they scent the water with";
	::reset(arg);
       replace_program("room/room");
}


