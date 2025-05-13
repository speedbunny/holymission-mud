inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);	
	short_desc="Outer Yard";
	long_desc="You have entered the outer ward. You stand about 20 feet "+		"from the protective wall. The temple is raised on a pagoda above "+
	"you. Plants grow sparsly around you. \n";

	DD= ({ ZZ+"/ward8", "north",
		ZZ+"/ward10", "south" });

	items= ({ "wall" "The stone wall surounds the temple",
		"pagoda", "The pagoda lifts the first level above the ground",
		"plants", "Mostly dandelions" });
	::reset(arg);
	replace_program("room/room");
	}

