#include "/players/qclxxiv/root/rootroom.h"
object eelworm;
object eelworm2;

extra_reset(arg) { 
	if (!eelworm) {
		eelworm = clone_object("players/qclxxiv/root/eelworm");
		move_object(eelworm, this_object());
	}
	if (!eelworm2) {
		eelworm2 = clone_object("players/qclxxiv/root/eelworm");
		move_object(eelworm2, this_object());
	}
	if (arg) return; 
	mayexit = 0; 
	return 1; 
}

ONE_EXIT(	ROOT+"w4","up",
"In the massive root system of a giant leaf",
"You are deep in the massive root system of a giant leaf.\n", 1)

