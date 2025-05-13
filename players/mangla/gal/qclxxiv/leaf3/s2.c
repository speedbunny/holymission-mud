#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
query_qnewbie() { return 1; }

FOUR_EXIT( HOME+"leaf3/s1","southwest",  HOME+"leaf3/s3","northeast",
			HOME+"leaf3/e01", "north", HOME+"leaf3/e02", "east",
"A small street", 
"A small street running into an old and decayed fishing-village.\n"
+"From here the first houses already show the typical diagonal positioning\n"
+"along the street: All doors facing to the south or to the west.\n",
1)
towadden() { return "southwest"; }

init() {
	::init();
	add_action( "do_get", "get" );
}

extra_reset(arg) {
	if (arg) return;
    set_nodig(1);
	items = ({
		"street" , "Just a bumpy old bricked street",
	});
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "street" : write("How do you plan to carry that?\n"); break;
		default: return 0;
	}
	return 1;
}
