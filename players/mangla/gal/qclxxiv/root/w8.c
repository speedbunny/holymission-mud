#include "/players/qclxxiv/root/rootroom.h"
object eelworm;

extra_reset(arg) { 
	if (!eelworm) {
		eelworm = clone_object("players/qclxxiv/root/eelworm");
		move_object(eelworm, this_object());
	}
	if (arg) return; 
	mayexit = 0; 
	return 1; 
}

FOUR_EXIT(	ROOT+"w2","up",
			ROOT+"w10",	"westdown",
			ROOT+"w12",	"eastdown",
			ROOT+"w14",	"down",
"In the massive root system of a giant leaf",
"You are deep in the massive root system of a giant leaf.\n", 1)

