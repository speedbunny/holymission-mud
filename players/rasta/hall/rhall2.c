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

TWO_EXIT( "players/rasta/hall/rhall3","north",
"players/rasta/hall/rhall1","south",
"A dark rock-hewn tunnel",
"A dark rock-hewn tunnel. The faint light shed by musts covering the walls\n"
+"starts to dominate turning the scene into a spooky play of shades.\n"
, 1)


