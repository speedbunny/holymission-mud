inherit "room/room";
#include "/players/trout/defs.h"


reset(arg){

	if(arg) return;
	set_light(1);	
	short_desc="Reception Room";

	long_desc="You are now standing in a plush reception room. This is "+

	"where any social events take place in the dojo. There is a small "+
	"table in the center of the room, surrounded by chairs. The walls "+
	 "are mostly made of opaque paper. There is a sliding door to the "+
	"north. \n";
	DD= ({ ZZ+"/dojo7", "north",
		ZZ+"/dojo1", "west",
		ZZ+"/dojo2", "east" });
	items= ({ "walls", "The walls are made from thin wooden frames and "+
	"large paper panels" });
	switch(RAN(2))
	     { 
		case 0: MO(CO(MM+"/sifu"), TO());
			break;
		default: break;
	     }
	::reset(arg);
	replace_program("room/room");
	}
