inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){

	if(arg) return;
	set_light(1);
	short_desc= "Courtyard";

	long_desc="You are presently standing in the center of a large court"+
	"yard. To your east you see the back sides to the shops. You are "+
	 " surrounded on all sides by several minkas, totally enclosing "+
	"the area. Childrens toys lie scattered about here. \n";
	DD= ({ ZZ+"/minka1", "north",
		ZZ+"/minka2", "northwest",
		ZZ+"/minka3", "west",
		ZZ+"/minka4", "southwest",
		ZZ+"/minka5", "south",

		ZZ+"/alley1", "east" });

	items= ({ "minka", "Large huts made of thatch, home to the peasant "+			"population",
		"toys", "Various balls and wooden-carved toys" });
	::reset(arg);
	replace_program("room/room");
	}
