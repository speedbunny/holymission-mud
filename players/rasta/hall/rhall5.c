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
"The rock-hewn walls, ranging from the deepest black to darkish grey, are\n"
+"covered by crusty, phosphorescent musts",
				"musts",
"These crusty, phosphorescent musts cover the walls allover, and spread a\n"
+"faint orange light",
			});
}

//TWO_EXIT( "players/qclxxiv/hall/hall7","north",
TWO_EXIT( "room/plane8","north",
"players/rasta/hall/rhall4","south",
"In the middle of a dark rock-hewn tunnel",
"In the middle of a dark rock-hewn tunnel. To both sides the tunnel vanishes\n"
+"into darkness. The rock-hewn walls seem to vibrate lightly, in a deep, slow\n"
+"and compulsive rhythm.\n"
, 1)


