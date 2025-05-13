inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Shrub Garden";
	long_desc="You stand in the middle of a shrub garden. It has been "+
	"expertly landscaped. This garden is a sign of status and wealth. "+		"Much care has gone into it's cultivation. The sturdy wall surrounds"+
	" the south edge of the garden. A path continues west. \n";
	DD= ({ ZZ+"/garden2", "west", 
		ZZ+"/ward10", "east" });
	items= ({ "shrub", "They are neatlty trimmmed, and randomly placed",
		"wall", "That lovely outer wall",
		"path", "It continues through the rest of the garden" });
	::reset(arg);
	replace_program("room/room");
	}
