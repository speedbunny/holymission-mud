#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "In the holes are grabbits...the not too big ones are weak.\n";
}

extra_reset(arg) {
	if (arg) return;
	items = ({ "bushes", "Mostly elder trees, acacias and cacti",
			   "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "aloes plants", "Some aloes plants",
			   "plants", "Some aloes plants",
			   "dell", "You're right down in the middle of it!",
			   "hole", "A typical grabbit hole",
			   "hill", "A high, green covered hill",
			   "small hill", "A small, green covered hill"
			});
}


FOUR_EXIT( "players/qclxxiv/leaf1/l2","northwest",
"players/qclxxiv/leaf1/l5","east",
"players/qclxxiv/leaf1/l8","southeast",
"players/qclxxiv/leaf1/ghole1", "hole",
"A small dell",
"A small dell. All around you there are elder trees, acacias and cacti.\n"+
"Some aloes plants can also be found here. To the northwest there is a small\n"+
"hill. To the north you see a higher hill covered by thriving vegetation.\n"+
"A small hole in the ground suggests the presence of grabbits here.\n"
+"You hear some singing coming from the southeast every now and then.\n"
,1)
