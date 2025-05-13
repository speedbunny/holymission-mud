#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

ONE_EXIT( HOME+"leaf3/s4","west",  "A small place", 
"A small place in front of an old decayed house. A number- and a name-plate\n"
+"are on it, left of the old door.\n",
1)
towadden() { return "west"; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action( "do_open", "open" );
	add_action( "do_unlock", "unlock" );
	add_action("read", "read");
}

read(arg) {
	if (arg=="number-plate") {
		write( "4.\n");
		return 1;
	}
	if (arg=="name-plate") {
		write( "From what's left you read: M.v.n Di.k.\n");
		return 1;
	}
	return 0;
}

extra_reset(arg) {
	if (arg) return;
	items = ({
		"place" , "A small empty place. Once it may have been graveled",
		"house", "An old decayed house with remainders of white paint",
		"wall", "A scaled off wooden wall. Once it may have been white",
		"number-plate", "4",
		"name-plate", "From what's left you read: M.v.n Di.k",
		"door", "An old wooden door, scaled off to the bare wood",
		"hinges", "Solid, somewhat rusty hinges",
		"lock", "A solid, somewhat rusty lock",
		"paint", "How far to you think these descriptions go?",
	});
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
		case "lock" : write("You fail to rip it out of the door.\n"); break;
		case "paint" : write( "Oh come on!\n"); break;
		default: return 0;
	}
	return 1;
}

do_open(arg) {
	if (arg=="door") {
		write("The door is locked.\n");
		return 1;
	}
	return 0;
}

do_unlock(arg) {
	if (arg=="door" || arg=="door with key") {
		write("You can't unlock it. Obviously you don't have the right key.\n");
		return 1;
	}
	return 0;
}
