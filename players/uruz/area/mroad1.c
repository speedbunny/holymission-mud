
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Kyoto Main Road";
	long_desc= "This is the main road of Kyoto. Buildings line both "+
	"sides of the road. Most of them are shops and small businesses. The "+
	"bar is to your west. To the east is a parlor. The road continues "+
	"south. \n";
	DD= ({ ZZ+"/fief4", "north",
		ZZ+"/bar", "west",
		ZZ+"/parlor", "east",
		ZZ+"/mroad2", "south"});
	items= ({ "bar", "A sushi bar", 
		"parlor", "It appears to be a massage parlor"});

	::reset(arg);
	replace_program("room/room");
	}

