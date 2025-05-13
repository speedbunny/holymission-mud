#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Male dressing area",
	long_desc=
		"The male dressing room is small, painted white, with\n"+
		"storage chests for the boys to store clothing.\n";
	dest_dir=({
		AROOMS+"gym","west",
		 });
	items=({
	   "walls","The walls are painted white",
	   "chests","The chests are painted white as well, and are locked.\n",
	      });
	smell = "The dressing room smells sweet, as if scented";
	::reset(arg);
	replace_program("room/room");
}