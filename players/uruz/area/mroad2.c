

inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Kyoto Main Road";
	long_desc= "This is the main road of Kyoto. Buildings line both "+		"sides, mostly shops and businesses. You notice a small alley to "+
	"the west. Several men stand in the entrance of the building to the "+		"east. They laugh as you look towards them. \n";
	DD= ({ ZZ+"/mroad1", "north",
		ZZ+"/alley1", "west",
		ZZ+"/mroad3", "south",
		ZZ+"/dojo1", "east"});
	items= ({ "buildings", "The structures are practically on top of each"+
		" other. There is very little room wasted"
		"men", "They are all dressed in white gi's"
		"alley", "You can see it leads behind the shops"});
	::reset(arg);
	replace_program("room/room");
	}
