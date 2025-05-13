/* islgen 1.0 clean - island room 3-5 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dune";
#include "roommacros.h"
object animal1;

ONE_EXIT(
REGION+"i_3_6", "south",
"On top of a dune", 
"On top of a dune. A burnet rose, a dewberry and a cranberry are growing\nhere. Other dunes are to the northwest and southwest. A path leads down\nto a dell to the south. A few rabbit holes are around. Far to the north,\nsouth and northeast there are other dunes. There is forest to the \nsoutheast, east and northeast.\n"
,1 )
init() {
::init();
add_action("veg_bar","north");
add_action("veg_bar","northwest");
add_action("veg_bar","west");
add_action("veg_bar","southwest");
add_action("veg_bar","southeast");
add_action("veg_bar","east");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"finch");
	if (arg) return;
	x = 3;
	y = 5;
	lockno = 7;
	keyno = 1;
	items = ({ "item", "Which item? Be more specific",
"holes", "A few rabbit holes",
"rabbit holes", "A few rabbit holes",
"burnet rose", "A burnet rose. Its tiny little yellow-white roses are starting to flower",
"dewberry", "A dewberry bush. As it is not yet the season, it bears no berries",
"cranberry", "A cranberry plant. As it is not the season ir bears no fruits yet",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
"forest", "A dense and green mixed forest",
	});
}
