#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

query_qnewbie() { return 1; }
extra_reset(arg) {
	if (arg) return;
	items = ({ "bushes", "Mostly elder trees, acacias and cacti",
			   "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "orchids", "Some beautiful and sweet smelling orchids",
			   "hill", "You're right on top of it!"
			});
}

TWO_EXIT( "players/qclxxiv/circular/circ1","north",
"players/qclxxiv/leaf1/l6","southeast",
"You're in the southeastern finger of the leaf. Strangely enough you're on a\n"+
"small hill",
"You're in the southeastern finger of the leaf. Strangely enough you're on a\n"+
"small hill. Bushes bar your way except to the northwest and southeast.\n"+
"Elder trees, acacias, cacti, and some orchids surround this place.\n"+
"The view of the hilly landscape to the southeast is of astonishing beauty.\n"
,1)
