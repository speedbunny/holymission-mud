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
"The rock-hewn walls, ranging from the deepest black to darkish grey, are\n"
+"covered by crusty, phosphorescent musts",
				"musts",
"These crusty, phosphorescent musts cover the walls allover, and spread a\n"
+"faint orange light",
			});
}

TWO_EXIT( "players/qclxxiv/hall/hall5","north",
"players/qclxxiv/hall/hall7","south",
"A dark rock-hewn tunnel",
"A dark rock-hewn tunnel. One of those ancient secret tunnels between\n"
+"the mighty kingdom of the Q's and the dread realms of Prince Rasta.\n"
, 1)


