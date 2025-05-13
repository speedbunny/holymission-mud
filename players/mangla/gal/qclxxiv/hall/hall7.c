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
				"inscription",
"It can hardly be read in the faint orange light spread by the musts, yet\n"
+"after some effort it reads: Do not pray in any of the churches in town\n"
+"or guilds; a clean chapel can be found in Prince Rasta's area to the\n"
+"south",
			});
}

TWO_EXIT( "players/qclxxiv/hall/hall6","north",
"players/rasta/hall/rhall5","south",
"A dark rock-hewn tunnel",
"A dark rock-hewn tunnel. An inscription is carved into the walls.\n"
, 1)


