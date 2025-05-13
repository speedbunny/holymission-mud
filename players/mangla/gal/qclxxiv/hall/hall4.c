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

TWO_EXIT( "players/qclxxiv/hall/hall3","west",
"players/qclxxiv/hall/hall5","south",
"One end of a dark hallway",
"One end of a dark hallway. To the south an even darker tunnel starts.\n"
+"Indeed this seems to be one of those long-forgotten secret tunnels.\n"
, 1)


