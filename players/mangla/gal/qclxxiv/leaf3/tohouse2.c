#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object barrel;
object obj_1, obj_2;
query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Maybe enter house?\n";
}

ONE_EXIT( HOME+"leaf3/s3","west",  
"A small place", 
"A small place in front of an old house. A number- and a name-plate are on\n"
+"it, left of the old door. Large letters painted above the door read:\n"
+"Bu.zer. Boats.\n" , 1)
towadden() { return "west"; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action( "enter", "enter" );
	add_action( "knock", "knock" );
	add_action("read", "read");
}

read(arg) {
	if (arg=="number-plate") {
		write( "2.\n");
		return 1;
	}
	if (arg=="name-plate") {
		write(
		"Some letters have disappeared. Yet you can still read: A. B.yz.rd.\n");
		return 1;
	}
	return 0;
}

extra_reset(arg) {
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf3/tohouse2","house","players/qclxxiv/leaf3/inhouse2","west","red-copper","inhouse2","This is an old oaken door.\n",0,0,1)
	obj_1->set_invisible(1);
	items = ({ 
		"place" , "A graveled place",
		"house", "An old house, apparently running some kind of business",
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
		"number-plate", "2",
		"name-plate", 
			"Some letters have disappeared. Yet you can still read: A. B.yz.rd",
		"lock", "A solid greenish lock, apparently old copper",
		"hinges", "Solid greenish hinges, apparently old copper",
		"paint", "How far to you think these descriptions go?",
	});
	PLACE_IN_THIS( barrel, HOME+"leaf3/barrel" );
}

knock( arg ) {
	if (!arg || arg=="on door") {
		write("Someone shouts: Come in!\n");
		return 1;
	}
	return 0;
}

enter( arg ) {
	if (arg=="house") {
		if (obj_1->query_closed()) 
			tell_object(this_player(), "The door is closed.\n");
		else
			this_player()->move_player("into house", 
					"/players/qclxxiv/leaf3/inhouse2" );
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
		case "house" :
		case "wall" :
		case "place" : write("How do you plan to carry that?\n"); break;
		case "letters" : write("So this is how they keep disappearing!..."
								+" However, you don't succeed.\n"); break;
		case "lock" : write("You fail to rip it out of the door.\n"); break;
		case "paint" : write( "Oh come on!\n"); break;
		default: return 0;
	}
	return 1;
}
