#include "/players/qclxxiv/myroom.h"
#include "/players/qclxxiv/door.h"
object key_obj, dwarfsoldier;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
query_qnewbie() { return 1; }

extra_reset(arg) {
    if (!dwarfsoldier) {
    	dwarfsoldier = clone_object("players/qclxxiv/leaf7/dwarfsoldier");
    	move_object(dwarfsoldier, this_object());
		MAKE_KEY( key_obj, "copper","inshanty" );
    	move_object(key_obj, dwarfsoldier);
    }
	if (arg) return;
	items = ({ "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "hill", "You're right on top of it!",
			   "dells", "The dells below are covered by vegetation"
			});
}

FOUR_EXIT( "players/qclxxiv/leaf1/l3","north",
"players/qclxxiv/leaf1/l6","west",
"players/qclxxiv/leaf1/l8","south",
"players/qclxxiv/leaf1/l4","east",
"On top of a high green covered hill",
"You find yourself on top of a high green covered hill. All around you\n"+
"there are elder trees, acacias and cacti. All around the hill you can see\n"+
"dells nearly closed by the thriving vegetation. It's really peaceful here.\n"+
"You hear some singing coming from the south every now and then.\n" ,1)
