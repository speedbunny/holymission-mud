
inherit "room/room";
#include "/players/trout/defs.h"
int i, rnd;
reset(tick) {
	if(tick) return;
	set_light(0);
	short_desc= "Bottom of the Ane";	
	long_desc= "The are now at the bottom of the Ane. It is incredibly "+		"dark down here. The light here is barely visible. The floor is "+
	"very soft, but littered with stones. The river opens up to the "+		"south, and also continues to the west. \n";

	DD= ({ ZZ+"/fief6", "up",
		ZZ+"/river7", "west",
		ZZ+"/river9", "south",
		ZZ+"/river12", "southeast"});

	items= ({ "floor", "It is soft and squishy" });
	rnd= 1+RAN(4);
	for(i=0; i<rnd; i++){
				MO(CO(MM+"/fish"), TO());
			    }
	::reset(tick);
	replace_program("room/room");
	}
