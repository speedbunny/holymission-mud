inherit "room/room";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(0);
	short_desc= "A Dark Alley";
	long_desc= "You have entered a dark alley. The alley slits in two "+
	"directions here. The area is a bit more clean here. The signs of "+
	"activity are present. Sounds of battle come from the north. The "+
	"alley continues to the north and south. \n";
	DD= ({ ZZ+"/alley2", "west",
		ZZ+"/alley4", "north",
		ZZ+"/alley7", "south" });
	::reset(arg);
	replace_program("room/room");
	}
