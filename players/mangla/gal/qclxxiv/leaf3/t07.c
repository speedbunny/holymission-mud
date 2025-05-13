/* t07 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
#include "/players/qclxxiv/door.h"
ONE_EXIT( REGION+"s06", "south",
"A small place", 
"A small place in front of an old house. A number- and a name-plate are on\n"
+"it, left to the old door.\n"
, 1)

object obj_1, obj_2;

towadden() { return "south"; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action( "enter", "enter" );
	add_action("read", "read");
}

read(arg) {
	if (arg=="number-plate") {
		write( "7.\n");
		return 1;
	}
	if (arg=="name-plate") {
		write(
	"Some letters have disappeared. Yet you can still read: B v.n B.rgen.\n");
		return 1;
	}
	return 0;
}

extra_reset(arg) {
	if (arg) return;
    /* set_nodig(1); */
	MAKE_DOORS("players/qclxxiv/leaf3/t07","house","players/qclxxiv/leaf3/h07","south","iron","h07","This is an old oaken door.\n",1,0,1)
	obj_1->set_invisible(1);
	items = ({ 
		"place" , "A graveled place",
		"house", "An old house, apparently left empty",
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
		"number-plate", "7",
		"name-plate", 
	"Some letters have disappeared. Yet you can still read: B v.n B.rgen",
		"lock", "A solid greenish lock, apparently old iron",
		"hinges", "Solid greenish hinges, apparently old copper",
		"paint", "How far to you think these descriptions go?",
	});
}

enter( arg ) {
	if (arg=="house") {
		if (obj_1->query_closed()) 
			tell_object(this_player(), "The door is closed.\n");
		else
			this_player()->move_player("into house", 
					"/players/qclxxiv/leaf3/h07" );
		return 1;
	}
	return 0;
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "number-plate": 
		case "name-plate" :write("It's still firmly mounted to the wall.\n");
						break;
		case "door" : write("It still hangs firmly in its solid hinges.\n");
						break;
		case "hinges" : write("You can't get them out of the wall.\n"); break;
		case "lock" : write("You fail to rip it out of the door.\n"); break;
		default: return 0;
	}
	return 1;
}
