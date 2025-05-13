
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	short_desc= "Alleyway";
	long_desc= "You have entered a short alley. The dirt path is littered"+
	" with garbage. The walls are made of brick, and are covered with "+
	"illegible graffiti. To the west the alley opens up into much more"+
	".... \n";

	DD= ({ ZZ+"/courtyd", "west",
		ZZ+"/mroad2", "east"});
	items= ({ "garbage" "It everwhere! Pretty disgusting",
		"graffiti", "It looks as if it's written in another language"+
		". But you can't make anything out"});
	smell="This place reeks of rotting garbage. \n";
	::reset(arg);
	replace_program("room/room");
	}
