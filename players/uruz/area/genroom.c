inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);

	short_desc="General's Chambers";

	long_desc="You are standing in the personal living quarters of "+
	"Ito Hyuga, Tokugawa's head general. This small room has a luxurious"+
	"bed, table, chairs, and dressers. The room is fully carpeted. The "+
	"wall are painted white, and hold a few paintings and maps. There is "+
	"a sliding door to the east. \n";
	DD= ({ ZZ+"/guard1", "south",
		ZZ+"/throne", "east" });

	items= ({ "bed", "A huge canopy bed",
		"paintings", "Each one shows Ito at a different battle",
		"maps", "Maps of the battlefields, showing troop sizes and "+
		"movements",
		"door", "Another sliding paper door" });
	CL ({1, 1, "ito", MM+"/ito", 0});
	::reset(arg);
	replace_program("room/room");
	}
