#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
query_qnewbie() { return 1; }
extra_reset(arg) {
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

TWO_EXIT( "players/rasta/hall/rhall4","north",
"players/rasta/hall/rhall2","south",
"A dark rock-hewn tunnel",
"A dark rock-hewn tunnel. The rock-hewn walls seem to vibrate lightly, in a\n"
+"deep, slow and compulsive rhythm; more to be felt than to be heard.\n"
, 1)


