#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object thief;
extra_reset() {
	if (!thief) {
		thief = clone_object("players/qclxxiv/stem/thief");
		move_object(thief, this_object());
	}
    set_nodig(1);
}

query_qnewbie() { return 1; }

TWO_EXIT( "players/qclxxiv/stem/stem3","north",
"players/qclxxiv/stem/stem1","south",
"A small green juicy hall",
"You are in a small green juicy hall, inside the leaf's magically bend stem. \n"
+"Someone has written on the wall: If looking for a key...check out a dwarf!\n"+
"Reggae Dub is coming from all directions. Drum and bass are penetrating\n"+
"your body and soul, you can't keep yourself from dancing while you walk.\n", 1)

