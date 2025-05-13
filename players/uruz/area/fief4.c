
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Wooden Bridge";
	long_desc= "A wide bridge spans across the dark river Ane. This "+
	"looks like the only way to cross the Ane for miles. Across the "+
	"bridge lies the city of Kyoto. This bridge offers one of the city's"+
	" best fishing spots. \n";
	DD= ({ ZZ+"/fief2", "north",
		ZZ+"/mroad1", "south"});
	items= ({ "river", "The deep, dark river Ane",
		"bridge", "It looks as if this bridge has been here for "+			"decades",
		"city", "Daimyo Tokugawa's home city of Kyoto"});
	clone_list = ({1, 1, "man", MM+"/old_man", 0});
	::reset(arg);
	replace_program("room/room");
	}
