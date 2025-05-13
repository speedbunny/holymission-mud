#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object loot;
object fungus, wig1, wig2, grub, flea1;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	loot = 0;
	FRESH_IN_ROOM(fungus, LEAF+"fungus");
	PLACE_IN_ROOM(flea1, LEAF+"flea");
	PLACE_IN_ROOM(wig1, LEAF+"earwig");
	PLACE_IN_ROOM(wig2, LEAF+"earwig");
	PLACE_IN_ROOM(grub, LEAF+"gnatsgrub");
	if (arg) return;
	items = ({ 
				"path","The grubby remainders of what once has been a path",
				"track","The grubby remainders of what once has been a path",
				"statue",
"A statue of onyx of a long-locked man with a sword and a globe in his hands.\n"
+"The statue looks rather old. There is an inscription at the pedestal",
				"inscription","An inscription is engraved at the pedestal",
			});
}

THREE_EXIT( LEAF+"q15","west",
			LEAF+"q13","east",
			LEAF+"q8","northeast",
       	 "A smudgy, dark track",
"A smudgy, dark track that seems to have been a path. A stone statue stands\n"
+"aside. It's terribly cold down here and also rather humid. You start to\n"
+"tremble.\n" , 0)

init() {
	::init();
	add_action( "do_get", "get" );
	add_action("read","read");
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "statue": write("It's too heavy.\n"); break;
		default: return 0;
	}
	return 1;
}

read(arg) {
	string s;
	object qm;
	qm = "/players/qclxxiv/qquest/qmast";
	if (arg=="inscription") {
		write( "You read: \n"
+"Negusa Qcxxviii, Master of Region and Creature Curses (weird symbols follow).\n");
		s = (qm->lock_name2key(2, this_player()->query_real_name() ) == 6) ?
"This is a secret message to the brave adventurer that will come and\n"
+"kill the evil dragon. Dig at the place you will meet in a vision.\n" : 0;
		qinscription(s);
		if (s) {
			if (!loot) {
				loot = clone_object("/players/qclxxiv/qquest/vicinstone");
				move_object(loot, this_player());
				write("PANG!....a stone actually FELL on your head!\n");
			}
			else write(
"You feel that you should come back here later, and read again,\n"
+"as you get the idea that something essential is missing....\n" );
		}
		return 1;
	}
	return 0;
}
