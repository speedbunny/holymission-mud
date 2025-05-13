/* islgen 1.0 clean - island room 2-4 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dune";
#include "roommacros.h"
object animal1;

ONE_EXIT(
REGION+"i_2_3", "north",
"On top of a dune", 
"On top of a dune. A cranberry is growing here. A large dewberry bars the\nway down to a dell to the east. Other dunes are to the southeast and \nnortheast. A path leads down to the beach to the north. A few rabbit\nholes are around. Far to the south there is another dune. More of the\nbeach, and the whirling sea at the end of it, can be seen to the \nnorthwest, west and southwest.\n"
,1 )
init() {
::init();
add_action("veg_bar","northwest");
add_action("veg_bar","west");
add_action("veg_bar","southwest");
add_action("veg_bar","south");
add_action("veg_bar","southeast");
add_action("veg_bar","east");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"hawk");
	if (arg) return;
	x = 2;
	y = 4;
	items = ({ "item", "Which item? Be more specific",
"holes", "A few rabbit holes",
"rabbit holes", "A few rabbit holes",
"cranberry", "A cranberry plant. As it is not the season ir bears no fruits yet",
"large dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"large dewberry", "A dewberry bush. As it is not yet the season, it bears no berries",
"vegetation", "Thick, mixed vegetation",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
"sea", "The breakers are a mass of boiling whirlpools",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
