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

TWO_EXIT( "players/rasta/hall/rhall2","north",
"players/rasta/room/ibar","east",
"The south end of a rock-hewn tunnel",
"The south end of a rock-hewn tunnel. Light and sensimilla fragrance\n"
+"pour in from Rasta's Ital Bar to the east. To the north the tunnel\n"
+"leads into apparent darkness. It seems to be one of those ancient secret\n"
+"tunnels between the mighty kingdom of the Q's and the dread realm of\n"
+"Prince Rasta.\n"
, 1)


