#include "/players/qclxxiv/myroom.h"

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "If your level is below six, you can freely go in and out of\n"
			+"the root. Often you can find lots of stuff left by people.\n";
}
extra_reset(arg) { 
	if (arg) return; 
	items = ({ 
				"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
			});
	property=({ "has_fire" });
	return 1; 
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
}

TWO_EXIT(	"/players/qclxxiv/myshop", "north",
			"/players/qclxxiv/root/wentrance", "enter",
"In the porch to the root workers' entrance!!! \n"
+"Don't go on, and look around here first!",
"In the porch to the root workers' entrance...DO NOT ENTER unless you\n"
+"actually are a root worker. The work is hard, and you may not be allowed\n"
+"to leave until you finish the job.\n"
, 1)

