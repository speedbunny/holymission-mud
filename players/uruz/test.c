inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	short_desc= "test room";
	set_light(1);
	::reset(arg);
	replace_program("room/room");
	}
