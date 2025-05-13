#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

ONE_EXIT( "players/qclxxiv/entrance","west", "A small street.\n", 
"A small street running to the northeast, with a street-sign on a pole.\n", 1)

init() {
	::init();
	add_action( "do_get", "get" );
}

extra_reset(arg) {
	if (arg) return;
	items = ({
		"street" , "Just a bumpy old bricked street",
		"street-sign", "A blue sign with white letters reading: Dyke street",
		"pole", "Just an ordinary old wooden pole",
	});
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "street" : write("How will you carry a street?\n"); break;
		case "street-sign" : write("It is mounted too firmly.\n"); break;
		case "pole":write("It has been drilled deep into the ground.\n"); break;
		default: return 0;
	}
	return 1;
}
