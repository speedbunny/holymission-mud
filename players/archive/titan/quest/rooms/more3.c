#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc = "What the hell are you looking at (ty vymrdanec).\n";

	dest_dir =
	      ({CESTA+"more2","west",
	        CESTA+"more4","east",
		CESTA+"more9","south",
		CESTA+"more1","northeast"});
	}
