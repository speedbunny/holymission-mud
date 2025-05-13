inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Shrub Garden";
	long_desc="You stand at the end of the garden. The outer stone wall "+
	"corners in the garden here. A man made pond lies at the end near the"+
	" wall. A path goes back east. \n";
	DD= ({ ZZ+"/garden1", "east" });

	items= ({ "pond", "This peaceful pond is home to several types of "+
		"fish and frogs" });
	::reset(arg);
	replace_program("room/room");
	}
