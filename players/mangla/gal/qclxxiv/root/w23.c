#include "/players/qclxxiv/root/rootroom.h"
object eelworm;
object eelworm2;
object loot;

extra_reset(arg) { 
	loot = 0;
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

ONE_EXIT(	ROOT+"w22","up",
"In the massive root system of a giant leaf",
"You are at the deepest point of the massive root system of a giant leaf.\n"
+"It seems someone has been digging here recently.\n", 1)

dig(player) {
	if (!loot) {
		loot = clone_object("/players/qclxxiv/leaf5/map5.c");
		move_object(loot, this_object() );
		return "You find a map.\n";
	}
	return "You get the feeling someone was here earlier....\n"
			+"But maybe you just have to try later.\n";
}
