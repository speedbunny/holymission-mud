#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

query_qnewbie() { return 1; }
query_newbiehint() { 
	return 
	"In the holes are grabbits...the not too big ones are rather weak.\n";
}
extra_reset(arg) {
	if (arg) return;
	items = ({ "bushes", "Mostly elder trees, acacias and cacti",
			   "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "aloes plants", "Some aloes plants",
			   "orchids", "Some beautiful and sweet smelling orchids",
			   "plants", "Some aloes plants",
			   "dell", "You're right down in the middle of it!",
			   "hole", "A typical grabbit hole",
			   "hill", "A high, green covered hill",
			   "small hill", "A small, green covered hill"
			});
}

FOUR_EXIT( "players/qclxxiv/leaf1/l1","northwest",
"players/qclxxiv/leaf1/l4","southeast",
"players/qclxxiv/leaf1/l5","south",
"players/qclxxiv/leaf1/ghole2", "hole",
"A small dell",
"A small dell. All around you there are elder trees, acacias and cacti.\n"+
"Some aloes plants and a few orchids can be found here. To the northwest\n"+
"there is a small hill. To the south you see a higher green covered hill.\n"+
"A small hole in the ground indicates the presence of grabbits here.\n"
,1)
