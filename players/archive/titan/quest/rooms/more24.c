#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf.";
	long_desc = "What the hell are you looking at (ty vymrdanec).\n";

	dest_dir =
	      ({CESTA+"more23","west",
	        CESTA+"more20","north",
		CESTA+"more28","southwest"});
	}
