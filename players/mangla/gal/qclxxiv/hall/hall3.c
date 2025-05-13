#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object bat1, bat2;
query_qnewbie() { return 1; }
extra_reset(arg) {
	PLACE_IN_THIS(bat1,"/players/rasta/obj/bat");
	PLACE_IN_THIS(bat2,"/players/rasta/obj/bat");
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

TWO_EXIT( "players/qclxxiv/hall/hall2","west",
"players/qclxxiv/hall/hall4","east",
"A heavily descending dark hallway",
"A heavily descending dark hallway, with mould-covered walls.\n"
+"From the west some light from the shop in the Q's leaf still mingles with\n"
+"the spooky light shed by the moulds.\n"
, 1)


