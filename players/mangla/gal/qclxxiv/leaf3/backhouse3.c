#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

ONE_EXIT( HOME+"leaf3/pub","south",  "Inside the backroom of a pub", 
"Inside the backroom of a pub. The walls are empty.\n", 1)
towadden() { return "west"; }

init() {
	::init();
	add_action( "do_get", "get" );
}

extra_reset(arg) {
	if (arg) return;
    set_nodig(1);
	items = ({
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
	});
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "wall" : write("How do you plan to carry that?\n"); break;
		default: return 0;
	}
	return 1;
}
