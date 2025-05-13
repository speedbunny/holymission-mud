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

ONE_EXIT(	ROOT+"w22","eastup",
"In the massive root system of a giant leaf",
"You are very deep in the massive root system of a giant leaf.\n", 1)

