#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object rasta;

extra_reset(arg) {
	if (!rasta) {
		PLACE_IN_THIS(rasta,"/players/qclxxiv/leaf1/rastaman");
		rasta->set_lines( ({ "So Long Babylon A Fool I.....So Long\n",
							"So Long Babylon A Jus A Fool I...Sooo Long\n",
							"For the enemies around I\n",
							"Trying to depower I\n",
							"So Long Babylon A Jus A Fool I...Soo Long\n",
					}) );
	}
	if (arg) return;
	items = ({ "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "cannabis plants", "Some sweet smelling cannabis plants",
			   "cannabis", "Some sweet smelling cannabis plants",
			   "plants", "Some sweet smelling cannabis plants and some aloes",
			   "aloes plants", "Some aloes plants",
			   "dell", "You're right down in the middle of it!",
			   "small hill", "A small, green covered hill",
			   "hill", "A small, green covered hill"
			});
}

TWO_EXIT( "players/qclxxiv/connect","south",
"players/qclxxiv/leaf1/l7","northwest",
"A green dell, at the top of a giant leaf",
"A green dell at the top of a giant leaf. You can leave the leaf by going \n"+
"south. All around you there are elder trees, acacias and cacti.\n"+
"Cannabis plants and a few aloes plants are grown here. To the northwest\n"+
"there is a small hill. \n"
,1)
