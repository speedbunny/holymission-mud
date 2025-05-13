/* islgen 1.0 clean - island room 3-4 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dell";
#include "roommacros.h"
object animal1;

FOUR_EXIT(
REGION+"i_2_3", "northwest",
REGION+"i_4_3", "northeast",
REGION+"i_2_5", "southwest",
REGION+"i_4_5", "southeast",
"In a dell", 
"In a dell. A burnet rose, a dog rose and a sea buckthorn are growing\nhere. A large elder-grove bars the way to the north. Other dells are\nreachable to the southwest and northeast. Dunes are to the north, west\nand south. A path is leading into the forest to the southeast. The\nbeach can be reached to the northwest. Some rabbit holes are around.\n"
,1 )
init() {
::init();
add_action("veg_bar","north");
add_action("veg_bar","west");
add_action("veg_bar","south");
add_action("veg_bar","east");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"rabbit");
	if (arg) return;
	x = 3;
	y = 4;
	lockno = 8;
	keyno = 5;
	items = ({ "item", "Which item? Be more specific",
"holes", "Some rabbit holes",
"rabbit holes", "Some rabbit holes",
"large elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"burnet rose", "A burnet rose. Its tiny little yellow-white roses are starting to flower",
"dog rose", "A dog rose. Its pink roses are flowering",
"sea buckthorn", "A sea buckthorn. A small thorny tree",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"paths", "Paths into the dells",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
	});
}
