/* h08 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
#include "/players/qclxxiv/door.h"
NO_EXIT( 
"Inside a small house",
"Inside a small house. Like many houses in this decayed fishing-hamlet, its\n"
+"original inhabitants have long ago left it. Some light shines in through\n"
+"a window to the east.\n",
1 )

object key_obj, rat;

towadden() { return "west"; }

init() {
	::init();
	add_action( "do_get", "get" );
}

extra_reset(arg) {
	if (arg) return;
	PLACE_IN_THIS(rat, "/players/qclxxiv/leaf5/hugerat");
	rat->set_aggressive(1);
	MAKE_MYKEY( key_obj, "silver","h08" );
	key_obj->set_home(this_object());
   	move_object(key_obj, this_object());
    set_nodig(1);
	items = ({
		"window",
"A window to the east sheds some light in, and gives a view at the dyke",
		"dyke", "A steep dyke",
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
		"door", "An old oaken door",
		"hinges", "Solid greenish hinges, apparently old copper",
		"lock", "A solid greenish lock, apparently old silver",
	});
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "door" : write("It still hangs firmly in its solid hinges.\n");
						break;
		case "hinges" : write("You can't get them out of the wall.\n"); break;
		case "lock" : write("You fail to rip it out of the door.\n"); break;
		case "wall" : write("How do you plan to carry that?\n"); break;
		default: return 0;
	}
	return 1;
}

