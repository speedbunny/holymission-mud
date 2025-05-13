#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object obj_1, obj_2;
query_qnewbie() { return 1; }

extra_reset(arg) {
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf1/l7","shanty","players/qclxxiv/leaf1/inshanty1","southeast","copper","inshanty","This is a peeled off wooden door.\n",1,1,1)
	obj_1->set_invisible(1);
	items = ({ "bushes", "Mostly elder trees, acacias and cacti",
			   "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "hill", "You're right on top of it!",
				"shanty","A small shanty with a peeled off door",
				"lock", "A greenish copper lock",
			});
}

THREE_EXIT( "players/qclxxiv/leaf1/l4","north",
"players/qclxxiv/leaf1/l8","west",
"players/qclxxiv/leaf1/toproom1","southeast",
"On top of a small hill",
"On top of a small hill. Bushes bar your way except to the west, north, and\n"+
"southeast. Elder trees, acacias and cacti surround this place. A small shanty\n"+
"is almost covered from sight by the bushes that are abundantly present here.\n"
+"The view of the hilly landscape to the northwest is of astonishing beauty.\n"
+"You hear some singing coming from the west and southeast every now and then.\n"
,1)
