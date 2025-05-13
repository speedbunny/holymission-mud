#include "/players/qclxxiv/myroom.h"
object mybox, boxworm;

reset(arg) {
	if (!present("q174_boxworm")) {
		PLACE_IN_THIS( boxworm, HOME+"leaf1/boxworm" );
	}
	if (arg) return;
	set_light(1);
    set_nodig(1);
	short_desc = "Inside a large box";
	long_desc = "Inside a large box.\n";
	 property=({ "no_teleport" });
}

towadden() { return "out"; }

init() {
	::init();
	add_action("exit_player", "out" );
	add_action("exit_player", "exit" );
}

exit_player() {
	object tp;
	tp = this_player();
	if (mybox && !tp->query_npc() ) 
		mybox->exit_player(tp);
	if (!mybox || !environment(mybox))
    	this_player()->move_player( "from out of box", 
						"/players/qclxxiv/waitingroom" );
	else this_player()->move_player( "from out of box", environment(mybox) );
	return 1;
}

set_mybox(obj) {
	mybox = obj;
	if (!present("q174_boxworm")) {
		PLACE_IN_THIS( boxworm, HOME+"leaf1/boxworm" );
	}
	boxworm->set_num(mybox->get_num());
}

exit(tp) {
	if (mybox && !tp->query_npc() ) 
		mybox->save_exit_player(tp);
}

