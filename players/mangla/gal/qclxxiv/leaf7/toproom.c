#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
object key_obj, dwarfsoldier;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
    if (!dwarfsoldier) {
    	dwarfsoldier = clone_object("players/qclxxiv/leaf7/dwarfsoldier");
    	move_object(dwarfsoldier, this_object());
		MAKE_KEY( key_obj, "iron","inmush" );
    	move_object(key_obj, dwarfsoldier);
    }
	if (arg) return;
	items = ({ "trees", "Some birches",
				"tree", "An old silverish white birch",
				"birch", "An old silverish white birch",
				"wood", "The edge of a dense wood, made up of mostly birches",
				"woods",
				"Rather dense woods, made up of oaks, birches, and beeches",
				"birches", "Some birches, nearly silverish white",
				"track", "A tiny track, covered with tiny footprints",
				"castle", "It seems to be some other castle",
				"path", "It seems to lead to the castle",
			});
}

/*TWO_EXIT( "players/qclxxiv/connect","south",*/
ONE_EXIT( 
"players/qclxxiv/leaf7/r7","northeast",
"You're on the edge of a dense wood. It happens to be a giant leaf's top!",
"You're on the edge of a dense wood. Some birches are standing here.\n"+
"You realize that this place happens to be a giant leaf's top!\n"+
"If you look down you see a path and something like a castle. You think\n"+
"you could just make the jump down, but realize that you cannot climb back,\n"+
"as you are way above the surface here.\n"+
"A tiny track to the northeast leads into some rather dense wood.\n" ,1)

init() {
	::init();
    add_action("jump", "jump");
    add_action("jump", "down");
}

jump(str) {
	int tel;
	for (tel=0; tel<10; tel++)
		write( "You're falling down...................................\n" );
	this_player()->move_player("down#/room/deep_forest1");
	return 1;
}
