#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object obj_1, obj_2;
query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Maybe enter the pub?\n";
}

ONE_EXIT( HOME+"leaf3/s4","south",  "A small place", 
"A small place in front of a fisher-men's pub. A number- and a name-plate are\n"
+"hanging right of the door. On top of the facade has once been painted:\n"
+"'t Kott.rtj.. and in a different color: . :,..'{.w' below it.\n" , 1)
towadden() { return "south"; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action( "enter", "enter" );
	add_action( "knock", "knock" );
	add_action("read", "read");
}

read(arg) {
	if (arg=="number-plate") {
		write( "3.\n");
		return 1;
	}
	if (arg=="name-plate") {
		write( "It appears to be the 'FULL LICENSE' plate rather.\n");
		return 1;
	}
	return 0;
}

extra_reset(arg) {
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf3/tohouse3","pub","players/qclxxiv/leaf3/pub","south","bronze","pub","An old door.\n",0,0,1)
	obj_1->set_invisible(1);
	obj_2->set_invisible(1);
	items = ({ 
		"place" , "A graveled place",
		"house", 
"Apparently it is a fisher-men's pub. Like all houses in the village it has\n"
+"long ago been painted white\n",
		"pub", "You're gazing at the pub's facade",
		"facade","You're gazing at the pub's facade",
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
		"number-plate", "3",
		"name-plate", "It appears to be the 'FULL LICENSE' plate rather",
		"lock", "A solid lock, apparently bronze",
		"hinges", "Solid hinges, apparently bronze",
		"paint", "How far to you think these descriptions go?",
	});
}

knock( arg ) {
	if (!arg || arg=="on door") {
		write("Someone shouts: Come in!\n");
		return 1;
	}
	return 0;
}

enter( arg ) {
	if (arg=="house" || arg=="pub") {
		if (obj_1->query_closed()) 
			tell_object(this_player(), "The door is closed.\n");
		else
			this_player()->move_player("into pub", 
					"/players/qclxxiv/leaf3/pub" );
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
		case "pub" :
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

