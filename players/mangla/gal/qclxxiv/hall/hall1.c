#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
query_qnewbie() { return 1; }
extra_reset(arg) {
	if (arg) return;
    set_nodig(1);
	items = ({ "walls",
"The darkish green organic walls, in fact the inner-side of a giant hollow\n"
+"rhizome, are covered by slimy, phosphorescent moulds",
				"moulds",
"These slimy, phosphorescent moulds cover the walls allover, and spread a\n"
+"faint greenish light",
			});
}

TWO_EXIT( "players/qclxxiv/myshop","west",
"players/qclxxiv/hall/hall2","east",
"A slightly descending dark hallway",
"A slightly descending dark hallway, apparently a hollow rhizome of the\n"
+"giant leaf. The slimy, phosphorescent moulds covering the walls provide\n"
+"ample greenish light.\n"
, 1)


