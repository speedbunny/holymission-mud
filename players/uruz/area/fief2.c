inherit "/players/trout/area/random_peasant";

#include "/players/trout/defs.h"
reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Path into Tokugawa's Fief";

	long_desc= "You have now entered the fief of Tokugawa Ieyasu, "+
	"one of the great Daimyos of the region. You can see many buildings "+

	"to the south. \n";
	DD= ({ ZZ+"/fief1", "north",
	ZZ+"/fief4", "south",
	ZZ+"/fief3", "southwest",
	ZZ+"/fief5", "southeast"});

	items= ({ "path", "A simple dirt path",
		"fief", "All the territory owned by this Daimyo"});

	::reset(arg);
	replace_program("room/room");
	}
