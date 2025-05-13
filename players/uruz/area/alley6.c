inherit "room/room";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	short_desc= "A Dead End";
	long_desc= "You have reached the end of this alley. There is nothing "+
	"of interest here, as you are completely walled in. The only exit "+
	"is back to the south. \n";
	DD= ({ ZZ+"/alley5", "south" });
	CL ({1, 1, "lo pan", MM+"/lo_pan.c", 0});
	::reset(arg);
	replace_program("room/room");
	}
