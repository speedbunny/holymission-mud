#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc = "What the hell are you looking at (ty vymrdanec).\n";

	dest_dir =
	      ({CESTA+"more26","west",
	        CESTA+"more31","south",
		CESTA+"more22","north"});
	}
