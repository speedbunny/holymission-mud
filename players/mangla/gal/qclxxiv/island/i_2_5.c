/* islgen 1.0 clean - island room 2-5 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dell";
#include "roommacros.h"
object animal1, animal2;

FIVE_EXIT(
REGION+"i_1_5", "west",
REGION+"i_1_4", "northwest",
REGION+"i_3_4", "northeast",
REGION+"i_1_6", "southwest",
REGION+"i_3_6", "southeast",
"In a dell", 
"In a dell. A dewberry and a burnet rose are growing here. A large\ndewberry bars the way to the east. Other dells are reachable to the \nsoutheast and northeast. Dunes are to the north, south and east. The\nbeach can be reached to the northwest, west and southwest. A few\nrabbit holes are around.\n"
,1 )
init() {
::init();
add_action("veg_bar","north");
add_action("veg_bar","south");
add_action("veg_bar","east");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"rabbit");
	PLACE_IN_THIS(animal2,REGION+"finch");
	if (arg) return;
	x = 2;
	y = 5;
	lockno = 8;
	keyno = 6;
	items = ({ "item", "Which item? Be more specific",
"holes", "A few rabbit holes",
"rabbit holes", "A few rabbit holes",
"dewberry", "A dewberry bush. As it is not yet the season, it bears no berries",
"burnet rose", "A burnet rose. Its tiny little yellow-white roses are starting to flower",
"large dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"paths", "Paths into the dells",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
	});
}
