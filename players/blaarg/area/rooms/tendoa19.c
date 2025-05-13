#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,3,"sensai",MOB+"sensai",0,
	});
	set_light(1);
	short_desc="Tendo Practice Room--Central Area",
	long_desc=
	   "This is the central area of the practice room. The floor\n"+
	   "is padded by mats. There are three sensai here, teaching\n"+
	   "their students.\n";
	dest_dir=({
	  AROOMS+"tendoa17","southeast",
	  AROOMS+"tendoa18","east",
	  AROOMS+"tendoa07","northeast",
	  AROOMS+"tendoa08","north",
	  AROOMS+"tendoa09","northwest",
	  AROOMS+"tendoa20","west",
	  AROOMS+"tendoa15","southwest",
	  AROOMS+"tendoa16","south",
		 });
	items=({ 
	  "mirrors","The mirrors make the room look even bigger",
	  "mats","The mats are well-worn from the practicing students",
	      });
	smell = "The practice room smells of sweat";
	::reset(arg);
	replace_program("room/room");
}