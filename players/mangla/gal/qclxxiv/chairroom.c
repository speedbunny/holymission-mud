#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/castle.loc"

init() {
	object obj;
	::init();
}

exit(tp) {
	if (tp->query_chairsoul() ) {
		command("stand up",tp);
	}
}

#ifdef TESTSITE
move(string str) {
#else
status move(string str) {
#endif
	if (this_player()->query_chairsoul() ) {
		command("stand up",this_player());
		return 1; 
	}
	return ::move(str);
}
 
