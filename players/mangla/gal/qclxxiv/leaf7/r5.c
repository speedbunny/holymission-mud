#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

object beechnut, acorn;
object obj_1, obj_2;

extra_reset(arg) {
    if (!beechnut) {
    	beechnut = clone_object("players/qclxxiv/obj/beechnut");
    	move_object(beechnut, this_object());
    }
    if (!acorn) {
    	acorn = clone_object("players/qclxxiv/obj/acorn");
    	move_object(acorn, this_object());
    }
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf7/r5","mushroom","players/qclxxiv/leaf7/inmush1","west","iron","inmush","This is a tiny wooden door.\n",1,1,1)
	obj_1->set_invisible(1);

	items = ({ "trees", "Oaks, beeches, and some birches",
				"tree", "An old silverish white birch",
				"birch", "An old silverish white birch",
				"wood","Very dense wood, made up of oaks, birches, and beeches",
				"beech", "An old smooth beech",
				"birch", "An old silvery birch",
				"oak", "An old oak",
				"oaks", "Big old oaks, carrying acorns",
				"acorns", "Those in the trees are still green\n"+
							"and besides they are hanging far too high for you",
				"birches", "Some birches, nearly silverish white",
				"beeches", "Beautiful beeches carrying lots of beechnuts",
				"beechnuts", "Those in the trees are not ripe yet\n"+
							"and besides they are hanging far too high for you",
				"honeysuckle","Richly smelling honeysucle, embracing the trees",
				"ferns","Huge dark green ferns, covering most of the soil",
				"ivy","Ivy covering most of the trees",
				"mushroom","A small mushroom with a tiny door",
				"mushrooms","Small mushrooms with very tiny doors in them.\n"
							+"One seems to be big enough to enter",
				"track", "A tiny track, covered with tiny footprints",
				"tracks", "Tiny tracks, covered with tiny footprints",
				"lock", "A tiny iron lock",
			});
}

FOUR_EXIT( "players/qclxxiv/leaf7/r3","north",
"players/qclxxiv/leaf7/r6","east",
"players/qclxxiv/leaf7/r8","south",
"players/qclxxiv/leaf7/r4","west",
"A very dense wood, consisting mostly of oaks, birches, and beeches",
"A very dense wood, consisting of oaks, birches, and beeches, intertwined.\n"+
"with honeysuckle, ivy, and ferns. Small tracks lead to all main directions.\n"+
"Small footprints lead to and from several mushrooms. This place looks like\n"+
"a tiny little town though all inhabitants seem to be out in the woods.\n" ,1)

notify(str) {
	write(str);
	say(str);
}
/*
init() {
	::init();
	add_action("enter", "enter" );
	add_action("open", "open" );
	add_action("close", "close" );
	add_action("lock", "lock" );
	add_action("unlock", "unlock" );
}
*/
