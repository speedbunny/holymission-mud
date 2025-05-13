#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object loot;
query_qnewbie() { return 1; }

extra_reset(arg) {
	loot = 0;
	if (arg) return;
	items = ({ "bushes", "Mostly elder trees, acacias and cacti",
			   "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "cannabis plants", "Some sweet smelling cannabis plants",
			   "cannabis", "Some sweet smelling cannabis plants",
			   "plants", "Some sweet smelling cannabis plants",
			   "dell", "You're right down in the middle of it!",
			   "hill", "A high, green covered hill",
			   "small hill", "A small, green covered hill",
				"statue",
"A modest statue of a bearded, long-locked man with a staff and a spade.\n"
+"It looks ancient. There is an inscription at the pedestal",
				"inscription","An inscription is engraved at the pedestal",
			});
}

THREE_EXIT( "players/qclxxiv/leaf1/l3","northwest",
"players/qclxxiv/leaf1/l5","west",
"players/qclxxiv/leaf1/l7","south",
"A green dell",
"A green dell. All around you there are elder trees, acacias and cacti.\n"+
"Some orchids and a few cannabis plants surround a statue.   To the south\n"+
"there is a small hill. To the west you see a higher green covered hill.\n"+
"You hear some singing coming from the southeast every now and then.\n"
,1)

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
+"Negus Qxlvii, Master of Herbal Wizardry. ....(weird symbols follow).\n");
		s = (qm->lock_name2key(2, this_player()->query_real_name() ) == 0) ?
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
