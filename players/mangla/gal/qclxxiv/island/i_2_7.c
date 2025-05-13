/* islgen 1.0 clean - island room 2-7 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dell";
#include "roommacros.h"
object animal1, animal2;

SEVEN_EXIT(
REGION+"i_2_6", "north",
REGION+"i_1_7", "west",
REGION+"i_2_8", "south",
REGION+"i_1_6", "northwest",
REGION+"i_3_6", "northeast",
REGION+"i_1_8", "southwest",
REGION+"i_3_8", "southeast",
"In a dell", 
"In a dell. A burnet rose and a dog rose are growing here. A large\ndewberry bars the way to the east. Other dells are reachable to the \nsoutheast and northeast. Dunes are to the north and east. There is a\npath to the top of the north dune. The beach can be reached to the \nnorthwest, west, southwest and south.\n"
,1 )
init() {
::init();
add_action("veg_bar","east");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"rabbit");
	PLACE_IN_THIS(animal2,REGION+"rabbit");
	if (arg) return;
	x = 2;
	y = 7;
	items = ({ "item", "Which item? Be more specific",
"burnet rose", "A burnet rose. Its tiny little yellow-white roses are starting to flower",
"dog rose", "A dog rose. Its pink roses are flowering",
"large dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"large dewberry", "A dewberry bush. As it is not yet the season, it bears no berries",
"vegetation", "Thick, mixed vegetation",
"path",
"A path, or rather lack of vegetation, to the top of a dune",
"paths", "Paths onto a dune and into the dells",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
	});
}
