/* islgen 1.0 clean - island room 3-7 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dune";
#include "roommacros.h"
object animal1, animal2;

ONE_EXIT(
REGION+"i_4_7", "east",
"On top of a dune", 
"On top of a dune. A cranberry is growing here. A large dewberry bars the\nway down to a dell to the south. Other dunes are to the northwest and \nsoutheast. A path is leading down to the forest to the east. Some rabbit\nholes are around. Far to the north and southeast there are other\ndunes. There is more forest to the northeast. The beach, and the\nwhirling sea at the end of it, can be seen to the southwest.\n"
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
	y = 7;
	lockno = 7;
	keyno = 0;
	items = ({ "item", "Which item? Be more specific",
"holes", "Some rabbit holes",
"rabbit holes", "Some rabbit holes",
"cranberry", "A cranberry plant. As it is not the season ir bears no fruits yet",
"large dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"dewberry", "A large dewberry bush. As it is not yet the season, it bears no berries",
"vegetation", "Thick, mixed vegetation",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
"sea", "The breakers are a mass of boiling whirlpools",
"forest", "A dense and green mixed forest",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
