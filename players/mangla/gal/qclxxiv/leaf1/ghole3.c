#include "/players/qclxxiv/myroom.h"
object grabbit, gr2, gr3, gr4, gr5;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (!grabbit) {
		grabbit = clone_object("players/qclxxiv/grabbit2");
		move_object(grabbit, this_object());
	}
	if (!gr2) {
		gr2= clone_object("players/qclxxiv/grabbit3");
		move_object(gr2, this_object());
	}
	if (!gr3) {
		gr3= clone_object("players/qclxxiv/grabbit2");
		move_object(gr3, this_object());
	}
	if (!gr4) {
		gr4= clone_object("players/qclxxiv/grabbit3");
		move_object(gr4, this_object());
	}
	if (!gr5) {
		gr5= clone_object("players/qclxxiv/grabbit2");
		move_object(gr5, this_object());
	}
	if (arg) return;
	items = ({ "tunnel", "A dark tunnel",
			   "tunnels", "Dark tunnels"
			});
}

THREE_EXIT( 
		"players/qclxxiv/leaf1/ghole1","up",
		"players/qclxxiv/leaf1/ghole4","east",
		"players/qclxxiv/leaf1/ghole5","down",
       	 "A small dark grabbit hole",
 "You are in a small dark grabbit hole. Tunnels lead up, down and to east.\n" 
		, 0)
