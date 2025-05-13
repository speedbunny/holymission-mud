#include "/players/qclxxiv/myroom.h"
object grabbit, gr2, gr3, gr4, gr5;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (!grabbit) {
		grabbit = clone_object("players/qclxxiv/grabbit3");
		move_object(grabbit, this_object());
	}
	if (!gr2) {
		gr2= clone_object("players/qclxxiv/qgrabbit4");
		move_object(gr2, this_object());
	}
	if (!gr3) {
		gr3= clone_object("players/qclxxiv/grabbit3");
		move_object(gr3, this_object());
	}
	if (!gr4) {
		gr4= clone_object("players/qclxxiv/grabbit4");
		move_object(gr4, this_object());
	}
	if (!gr5) {
		gr5= clone_object("players/qclxxiv/grabbit3");
		move_object(gr5, this_object());
	}
	if (arg) return;
	items = ({ "tunnel", "A dark tunnel",
			   "tunnels", "Dark tunnels"
			});
}

TWO_EXIT( 
		"players/qclxxiv/leaf1/ghole4","eastup",
		"players/qclxxiv/leaf1/ghole3","westup",
       	 "A dark grabbit hole",
 "You are in a dark grabbit hole. Tunnels lead westup and eastup.\n" 
		, 0)
