#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object bat1, rat;
query_qnewbie() { return 1; }
extra_reset(arg) {
	PLACE_IN_THIS(bat1,"/players/rasta/obj/bat");
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

TWO_EXIT( "players/qclxxiv/hall/hall4","north",
"players/qclxxiv/hall/hall6","south",
"One end of a dark tunnel",
"One end of a dark tunnel. To the north a dark hallway starts, leading to\n"
+"the west. The orange light spread by the musts on the walls mingles with\n"
+"faint greenish light falling in from the hallway.\n"
, 1)


