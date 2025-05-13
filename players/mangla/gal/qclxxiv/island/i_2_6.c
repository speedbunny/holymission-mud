/* islgen 1.0 clean - island room 2-6 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dune";
#include "roommacros.h"
object animal1;

TWO_EXIT(
REGION+"i_2_7", "south",
REGION+"i_3_6", "east",
"On top of a dune", 
"On top of a dune. A dewberry is growing here. Other dunes are to the \nsoutheast and northeast. Paths lead down to dells to the south and east.\nA few rabbit holes are around. Far to the north and southeast there are\nother dunes. The beach, and the whirling sea at the end of it, can be\nseen to the northwest, west and southwest.\n"
,1 )
init() {
::init();
add_action("veg_bar","north");
add_action("veg_bar","northwest");
add_action("veg_bar","west");
add_action("veg_bar","southwest");
add_action("veg_bar","southeast");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"hawk");
	if (arg) return;
	x = 2;
	y = 6;
	items = ({ "item", "Which item? Be more specific",
"holes", "A few rabbit holes",
"rabbit holes", "A few rabbit holes",
"dewberry", "A dewberry bush. As it is not yet the season, it bears no berries",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"paths", "Paths into the dells",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
"sea", "The breakers are a mass of boiling whirlpools",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
