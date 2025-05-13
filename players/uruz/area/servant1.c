inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){

	if(arg) return;
	set_light(1);
	short_desc="Servant's Quarters";
	long_desc="This small room houses the entire servant staff of Honno "+

	"Ji. Bunk beds stand crammed against one another. There is very "+		"little room for personal belongings. There is a door to the north, "+
	"and one to the east. This room is so small, you'd have to leave "+		"just to change your mind!! \n";
	DD= ({ ZZ+"/kitchen", "north",
		ZZ+"/tearoom", "east" });
	items= ({ "bed", "Plain bunk beds" });

	::reset(arg);
	replace_program("room/room");
	}

