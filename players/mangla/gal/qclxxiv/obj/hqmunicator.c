inherit "/players/qclxxiv/obj/qmunicator";
#define FILENAME "players/qclxxiv/obj/hqmunicator"	/* change if neccessary */
query_auto_load() { return FILENAME+":"+"not_used"; }
reset(arg) {
	::reset(arg);
	if (arg) return;
	hidden = 1;
}

init() {
	::init();
	add_action("em","em");
}

em(arg) {
	tell_room(environment(this_player()),arg+"\n");
	return 1;
}
