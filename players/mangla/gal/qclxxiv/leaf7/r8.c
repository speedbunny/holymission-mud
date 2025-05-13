#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
object beechnut, acorn;
object dwarfsoldier;
object obj_1, obj_2;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

init() {
	::init();
	add_action("pit","enter");
}

pit(arg) {
	if (arg!="pit" && arg!="dark pit") return 0;
	this_player()->move_player("into pit","/players/qclxxiv/leaf7/mine1");
	return 1;
}

extra_reset(arg) {
    if (!dwarfsoldier) {
    	dwarfsoldier = clone_object("players/qclxxiv/leaf7/dwarfsoldier");
    	move_object(dwarfsoldier, this_object());
    }
    if (!beechnut) {
    	beechnut = clone_object("players/qclxxiv/obj/beechnut");
    	move_object(beechnut, this_object());
    }
    if (!acorn) {
    	acorn = clone_object("players/qclxxiv/obj/acorn");
    	move_object(acorn, this_object());
    }
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf7/r8","mushroom","players/qclxxiv/leaf7/insmith1","west","iron","insmith","This is a tiny wooden door.\n",0,0,0)
	obj_1->set_invisible(1);
	items = ({ "trees", "Oaks, beeches, and some birches",
				"tree", "An old silverish white birch",
				"birch", "An old silverish white birch",
				"beech", "An old smooth beech",
				"oak", "An old oak",
				"pit", "a dark pit",
				"wood",
				"Moderately dense wood, made up of oaks, birches, and beeches",
				"woods","Denser woods, made up of oaks, birches, and beeches",
				"oaks", "Big old oaks, carrying acorns",
				"acorns", "Those in the trees are still green\n"+
							"and besides they are hanging far too high for you",
				"birches", "Some birches, nearly silverish white",
				"beeches", "Beautiful beeches carrying lots of beechnuts",
				"beechnuts", "Those in the trees are not ripe yet\n"+
							"and besides they are hanging far too high for you",
				"track", "A tiny track, covered with tiny footprints",
				"path", "A very small path, covered with tiny footprints",
				"mushroom","A small mushroom with a tiny door",
				"mushrooms","Small mushrooms with very tiny doors in them.\n"
							+"One seems to be big enough to enter",
			});
}

THREE_EXIT( "players/qclxxiv/leaf7/r5","north",
"players/qclxxiv/leaf7/r6","northeast",
"players/qclxxiv/leaf7/r7","west",
"A moderately dense wood, consisting mostly of birches, beeches, and oaks",
"A moderately dense wood, consisting mostly of birches, beeches, and oaks.\n"+
"A dark pit. Some mushrooms. You're trodding a small path, but surely this\n"+
"is a VERY small path. It seems to go from northeast to west, but to the north\n"+
"another small track leads into quite somewhat denser woods.\n" ,1)
