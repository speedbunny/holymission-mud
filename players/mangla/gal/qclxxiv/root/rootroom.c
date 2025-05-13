/* root room is common part of all 'root-rooms'. The rootroom can not
// be instantiated as it has no extra_reset nor reset (..EXIT room macro).
// Each room derived from rootroom MUST priovide these two therefore.
*/
#include "/players/qclxxiv/myroom.h"

#define ROOT "players/qclxxiv/root/"
int mayexit; 
query_qnewbie() { return 1; }

reset(arg) {
	::reset(arg);
	if (arg) return;
/*
	items = ({ "walls", "The walls are slightly illuminating",
				"wall", "The walls are slightly illuminating",
				"root", "The entire root system is slightly illuminating",
				"fibrils","Strong, elastic, slightly illuminating fibrils",
			});
*/
}

init() {
	::init();
 	add_action("setexit","setexit"); 
 	add_action("hide","hide");  /* to prevent error with thiefs soul */
	add_action("hold","hold");  /* eelworms are FAR too easy otherwise */
	add_action("hold","smash");  /* eelworms are FAR too easy otherwise */
	add_action("backstab","backstab"); /* eelworms are FAR too easy otherwise */
}

exit(obj) {
	if (obj->query_npc()) return;
	if (!(mayexit || obj->query_ghost() 
			|| obj->query_level()>29 || obj->query_level()<=5 ) ) {
	 	call_out("check_next_room", 0, obj ); 
	}
	return;
}

setexit(arg) { if (this_player()->query_level()>29) mayexit = 1; return 1; }

yes_its_a_root_room() { return 1; }

check_next_room(obj) {
	if ( !(environment(obj))->yes_its_a_root_room() ) {
		write("You try to leave the root system.........\n");
		write("You feel the root system's elastic fibrils pulling you back.\n");
	 	obj->move_player("back#"+file_name(this_object()) ); 
		write("The root system takes back it's normal form....\n");
		write(
	"No damage can be found at the spot where you stressed the fibrils.\n");
	}
}

hide() {
	write("You can't do that here.\n" );
	return 1;
}

hold() {
	write(
"You can't do that. Everything is slippery in here, especially the eelworms.\n" );
	return 1;
}

backstab(arg) {
	write("You can't get at the backside of a worm! Which would it be?\n");
	return 1;
}
