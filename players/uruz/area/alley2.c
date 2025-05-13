inherit "room/room";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(0);
	short_desc= "A Dark Alley";
	long_desc= "You have discovered a dark alleyway. It looks as if no "+
	"one has been here in quite a long time. Garabage litters the area. "+
	"There is very little room crammed in between the buildings here. The"+
	" alley continues east. \n";
	DD =({ ZZ+"/mroad3", "west",
		ZZ+"/alley3", "east" });
	items= ({ "garbage", "Lots of paper products" });
	::reset(arg);
	replace_program("room/room");
	}
