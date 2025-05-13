inherit "room/room";
#include "/players/trout/defs.h"

int i, rnd;
reset(arg){
	if(arg) return;
	set_light(0);
	short_desc="Bottom of the Ane";
	long_desc="You are now at the bottom of the Ane. It is incredibly "+
	"dark down here. The light here is barely visible. The floor "+
	"is very soft, and littered with stones. \n";
	
	items= ({ "floor", "It's soft and squishy" });
	rnd= 1+RAN(4);
	for(i=0; i<rnd; i++){
			MO(CO(YY+"/mobs/fish"), TO());
		}
	DD= ({ ZZ+"/river8", "northwest",
		ZZ+"/river9", "west",
		ZZ+"/river10", "southwest",
		ZZ+"/river13", "northeast" });
	::reset(arg);
	replace_program("room/room");
	}
