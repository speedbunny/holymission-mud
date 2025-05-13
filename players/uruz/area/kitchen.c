inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Kitchen";
	long_desc="You are now in the kitchen of Honno Ji. Several wood "+		"burning stoves fill the southern end of the room. There are shelves"+
	" filled with pots, pans, plates, glassware, and untensils of all "+

	"sorts. This kitchen is required to feed an army every day. \n";
	DD= ({ ZZ+"/servant1", "south",
		ZZ+"/recept", "east" });	
	items= ({ "pots", "They're pots, what'd ya expect??",
		"pans", "They're pans, what'd ya expect??",
		"plates", "Stacks of fine china",
		"glassware", "Lots of glasses, all made from crystal",
		"stoves", "Big enough to fit a person in!!" });
	::reset(arg);
	replace_program("room/room");
	}
