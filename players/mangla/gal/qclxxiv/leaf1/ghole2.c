#include "/players/qclxxiv/myroom.h"
object grabbit, gr2, gr3, gr4, gr5;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (!grabbit) {
		grabbit = clone_object("players/qclxxiv/grabbit1");
		move_object(grabbit, this_object());
	}
	if (!gr2) {
		gr2= clone_object("players/qclxxiv/grabbit2");
		move_object(gr2, this_object());
	}
	if (!gr3) {
		gr3= clone_object("players/qclxxiv/grabbit1");
		move_object(gr3, this_object());
	}
	if (!gr4) {
		gr4= clone_object("players/qclxxiv/grabbit2");
		move_object(gr4, this_object());
	}
	if (!gr5) {
		gr5= clone_object("players/qclxxiv/grabbit1");
		move_object(gr5, this_object());
	}
	if (arg) return;
	items = ({ "opening", "An opening allows some light to shine in",
			   "tunnel", "A dark tunnel",
			   "tunnels", "Dark tunnels"
			});
}

THREE_EXIT( 
		"players/qclxxiv/leaf1/l3","up",
		"players/qclxxiv/leaf1/ghole1","west",
		"players/qclxxiv/leaf1/ghole4","down",
       	 "A small grabbit hole",
       	 "You are in a small grabbit hole. An opening leads up, tunnels\n"+
		"lead down and to the west.\n" , 1)
