#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc =
		  "In this part of sea is water pleasant warm and very clear. Sea floor \n"
		+ "goes slowly down. It is covered with sand and shells. But sometimes \n"
		+ "appears rocks scattered on sea floor.\n";

	smell = "You are under water. You smell nothing";
	items = ({
		"water","Water is transparent and pleasant warm",
		"sea floor","Sea floor is covered with sand and large quanties of shells", 
		"floor","Sea floor is covered with sand and large quanties shells",
		"shells","There are much shells with different origin",
		"rocks","Big and heavy rocks probably falls down from peaks standing around",
		"sand","It looks like gold"});


	dest_dir =
	      ({CESTA+"more13","west",
	        CESTA+"more15","east",
		CESTA+"more21","south",
		CESTA+"more7","north"});
	}
