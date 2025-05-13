#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object rat;
query_qnewbie() { return 1; }
extra_reset(arg) {
	PLACE_IN_THIS(rat,"/players/qclxxiv/leaf5/rat");
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

TWO_EXIT( "players/qclxxiv/hall/hall1","west",
"players/qclxxiv/hall/hall3","east",
"A descending dark hallway",
"A descending dark hallway, apparently a hollow rhizome of the\n"
+"giant leaf. This seems to lead to one of those ancient secret tunnels\n"
+"between the two Rastafarian empires rooting in the early mists of history.\n"
, 1)


