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

FOUR_EXIT(	ROOT+"w21","up",
			ROOT+"w18",	"westdown",
			ROOT+"w19",	"eastdown",
			ROOT+"w23",	"down",
"In the massive root system of a giant leaf",
"You are very deep in the massive root system of a giant leaf.\n", 1)

