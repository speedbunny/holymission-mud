/* islgen 1.0 clean - island room 3-8 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dell";
#include "roommacros.h"
object animal1, animal2;

FOUR_EXIT(
REGION+"i_2_8", "west",
REGION+"i_3_9", "south",
REGION+"i_2_7", "northwest",
REGION+"i_2_9", "southwest",
"In a dell", 
"In a dell. A sea buckthorn, a burnet rose and a dog rose are growing\nhere. A large elder-grove bars the way to the north. Another dell can\nbe reached to the northwest. Dunes are to the north, southeast and \neast. The beach can be reached to the west, southwest and south.\n"
,1 )
init() {
::init();
add_action("veg_bar","north");
add_action("veg_bar","southeast");
add_action("veg_bar","east");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"fieldmouse");
	PLACE_IN_THIS(animal2,REGION+"quail");
	if (arg) return;
	x = 3;
	y = 8;
	lockno = 8;
	keyno = 7;
	items = ({ "item", "Which item? Be more specific",
"large elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"sea buckthorn", "A sea buckthorn. A small thorny tree",
"burnet rose", "A burnet rose. Its tiny little yellow-white roses are starting to flower",
"dog rose", "A dog rose. Its pink roses are flowering",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
	});
}
