#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
query_qnewbie() { return 1; }

FOUR_EXIT( HOME+"leaf3/s2","southwest",  HOME+"leaf3/s4","northeast",
			HOME+"leaf3/tohouse1", "north", HOME+"leaf3/tohouse2", "east",
"A small street", 
"A small street running through an old and decayed fishing-village.\n"
+"To the north and east houses face the street behind their small places.\n",
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
		"place", "A small place in front of the house",
		"places", "Small places in front of the houses",
		"house","It looks old and decayed. Once it may have been painted white",
		"houses", 
	"They look old and decayed. Long ago they may have been painted white",
		"street" , "Just a bumpy old bricked street",
	});
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "house" :
		case "houses" :
		case "street" : write("How do you plan to carry that?\n"); break;
		default: return 0;
	}
	return 1;
}
