inherit "room/room";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	short_desc="A Narrow Alley";
	long_desc= "The alley narrows off here, to barely shoulder width "+
	"apart. Broken glass can sparkles from the floor as you walk by. "+
	"The alley continues south. \n";
	DD= ({ ZZ+"/alley3", "north",
		ZZ+"/alley8", "south" });
	items= ({ "glass", "Don't trip, you'd cut yourself easily on it"});
	::reset(arg);
	replace_program("room/room");
	}
