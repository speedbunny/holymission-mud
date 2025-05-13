#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Male dressing area",
	long_desc=
		"The male dressing room is small, painted white, with\n"+
		"storage chests for the mail bathers to store clothing.\n";
	dest_dir=({
		AROOMS+"bath3","south",
	 });
	items=({
	   "walls","The walls are painted white",
	   "chests","The chests are made of bamboo. You can't open them",
	      });
	smell = "The dressing room smells sweet, as if scented";
	::reset(arg);
	replace_program("room/room");
}
