#include "/players/qclxxiv/myroom.h"
object dwarfking;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
    if (!dwarfking) {
    	dwarfking = clone_object("players/qclxxiv/leaf7/dwarfking");
    	move_object(dwarfking, this_object());
    }
	if (arg) return;
	items = ({ "trees", "Oaks, beeches, and some birches",
				"tree", "An old silverish white birch",
				"birch", "An old silverish white birch",
				"beech", "An old smooth beech",
				"oak", "An old oak",
				"wood","Dense wood, made up of oaks, birches, and beeches",
				"woods","Open woods, made up of oaks, birches, and beeches",
				"oaks", "Big old oaks",
				"birches", "Some birches, nearly silverish white",
				"beeches", "Beautiful beeches",
				"track", "A tiny track, covered with tiny footprints",
				"path", "A very small path, covered with tiny footprints"
			});
}

THREE_EXIT( "players/qclxxiv/leaf7/r4","north",
"players/qclxxiv/leaf7/r8","east",
"players/qclxxiv/leaf7/toproom","southwest",
"A dense wood, consisting mostly of oaks, birches, and some beeches",
"A dense wood, consisting mostly of oaks, birches, and some beeches.\n"+
"It looks like you're on a small open place, but surely this is a VERY\n"+
"small open place. The small path goes north and east, but to the southwest\n"+
"another tiny track leads into more open woods.\n" ,1)
