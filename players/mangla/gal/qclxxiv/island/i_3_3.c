/* islgen 1.0 clean - island room 3-3 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dune";
#include "roommacros.h"
object animal1, animal2;

ONE_EXIT(
REGION+"i_4_3", "east",
"On top of a dune", 
"On top of a dune. A dog rose is growing here. A large elder-grove bars\nthe way down to the west. A large dewberry bars the way down to a dell\nto the south. Another dune is to the southwest. A path leads down to a\ndell to the east. Far to the south and east there are other dunes.\nThere is forest to the southeast. The beach, and the whirling sea at\nthe end of it, can be seen to the north, northwest, west and \nnortheast.\n"
,1 )
init() {
::init();
add_action("veg_bar","north");
add_action("veg_bar","northwest");
add_action("veg_bar","west");
add_action("veg_bar","southwest");
add_action("veg_bar","south");
add_action("veg_bar","southeast");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"finch");
	PLACE_IN_THIS(animal2,REGION+"finch");
	if (arg) return;
	x = 3;
	y = 3;
	items = ({ "item", "Which item? Be more specific",
"large elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"large dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"dog rose", "A dog rose. Its pink roses are flowering",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
"sea", "The breakers are a mass of boiling whirlpools",
"forest", "A dense and green mixed forest",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
