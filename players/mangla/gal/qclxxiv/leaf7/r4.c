#include "/players/qclxxiv/myroom.h"
object beechnut;
object dwarfsoldier;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
    if (!beechnut) {
    	beechnut = clone_object("players/qclxxiv/obj/beechnut");
    	move_object(beechnut, this_object());
    }
    if (!dwarfsoldier) {
    	dwarfsoldier = clone_object("players/qclxxiv/leaf7/dwarfsoldier");
    	move_object(dwarfsoldier, this_object());
    }
	if (arg) return;
	items = ({ "trees", "Oaks, birches, and some beeches",
				"tree", "An old oak",
				"oak", "Yet another old oak",
				"beech", "An old smooth beech",
				"birch", "An old silvery birch",
				"wood", "A dense wood, made up of oaks, birches, and beeches",
				"woods", "Dense woods, made up of oaks, birches, and beeches",
				"oaks", "Big oaks, most of them already very old",
				"birches", "Some birches, nearly silverish white",
				"beeches", "Beautiful beeches carrying lots of beechnuts",
				"beechnuts", "Those in the trees are not ripe yet\n"+
							"and besides they are hanging far too high for you",
				"path", "A very small path, covered with tiny footprints",
				"track", "A tiny track, covered with tiny footprints"
			});
}

THREE_EXIT( "players/qclxxiv/leaf7/r3","northeast",
"players/qclxxiv/leaf7/r5","east",
"players/qclxxiv/leaf7/r7","south",
"A rather dense wood, consisting mostly of oaks, birches, and beeches",
"A rather dense wood, consisting mostly of oaks, birches, and beeches.\n"+
"It looks like you're trodding some small path, but surely this is a VERY\n"+
"small path. It seems to go from northeast to south, but to the east another\n"+
"small track leads into even denser woods.\n" ,1)
