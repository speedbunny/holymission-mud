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

TWO_EXIT(	ROOT+"w3","westup",
			ROOT+"w7",	"down",
"In the massive root system of a giant leaf",
"You are in the massive root system of a giant leaf.\n", 1)

