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

FOUR_EXIT(	ROOT+"work","up",
			ROOT+"w2",	"westdown",
			ROOT+"w3",	"eastdown",
			ROOT+"w20",	"down",
"In the massive root system of a giant leaf",
"You are in the massive root system of a giant leaf.\n", 1)

