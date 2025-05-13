#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
/*
object griffin, notebook;
*/
object tidemaster, regionmaster;

extra_reset(arg) {
/*	if (!griffin) {
		griffin = clone_object("players/qclxxiv/griffin");
		move_object(griffin, this_object());
	}
	if (!notebook) {
		notebook = clone_object("players/qclxxiv/notebook");
		move_object(notebook, this_object());
	}
*/
	if (!tidemaster)
		PLACE_IN_THIS(tidemaster, "/players/qclxxiv/leaf4/tidemaster");
	if (!regionmaster)
		PLACE_IN_THIS(regionmaster, "/players/qclxxiv/leaf4/regionmaster");
	if (arg) return;
	items = ({ "pole", "A solidly grounded pole",
			});
}

TWO_EXIT( "players/qclxxiv/circular/circ4","south",
		 	"players/qclxxiv/leaf4/t_3_0","north",
       	 "Entrance to the Misty Wadden",
"Entrance to the northern finger. In this finger of the leaf some wizard has\n"
	+"created the Misty Wadden. Maybe you should go south right now..\n",1)

is_tide_exit() { return 1; }
is_to_exit() { return 1; }

