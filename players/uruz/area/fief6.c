
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);	
	short_desc= "Ane Riverbank";
	long_desc= "You stand on the northern bank of the Ane river. A sign "+
	"is planted right near the water. You can see fish swimming about in "+
	"the river. \n";
	DD= ({ ZZ+"/fief5", "west",
		ZZ+"/river8", "dive"});
	items= ({ "river", "The deep, dark river Ane",	
		"fish", "A variety of fish swim here, but a rainbow trout "+			"catches your attention",
		"trout", "You could of swore it just winked at you",
		});
	MO(CO(YY+"/obj/sign2"), TO());
	::reset(arg);
	replace_program("room/room");
	}
