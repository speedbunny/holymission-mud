#include "/players/qclxxiv/myroom.h"
object beechnut;
object dwarfwiz;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
    if (!beechnut) {
    	beechnut = clone_object("players/qclxxiv/obj/beechnut");
    	move_object(beechnut, this_object());
    }
    if (!dwarfwiz) {
    	dwarfwiz = clone_object("players/qclxxiv/leaf7/dwarfwiz");
    	move_object(dwarfwiz, this_object());
    }
	if (arg) return;
	items = ({ "trees", "Oaks, birches, and some beeches",
				"tree", "An old oak",
				"oak", "An old oak",
				"beech", "An old smooth beech",
				"birch", "An old silvery birch",
				"birches", "Old silvery birches",
				"wood", "A dense wood, made up of oaks, birches, and beeches",
				"woods", "Dense woods, made up of oaks, birches, and beeches",
				"oaks", "Big oaks, most of them already very old",
				"beeches", "Beautiful beeches carrying lots of beechnuts",
				"beechnuts", "Those in the trees are not ripe yet\n"+
							"and besides they are hanging far too high for you",
				"path", "A very small path, covered with tiny footprints",
				"track", "A tiny track, covered with tiny footprints"
			});
}


THREE_EXIT( "players/qclxxiv/leaf7/r1","northeast",
"players/qclxxiv/leaf7/r4","southwest",
"players/qclxxiv/leaf7/r5","south",
"A rather dense wood, consisting mostly of oaks, birches, and beeches",
"A rather dense wood, consisting mostly of oaks, birches, and beeches.\n"+
"It looks like you're trodding some small path, but surely this is a VERY\n"+
"small path. It seems to go from northeast to southwest, but to the south\n"+
"another small track leads into even denser woods.\n" ,1)
