/* islgen 1.0 clean - island room 3-6 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/dell";
#include "roommacros.h"
object animal1, animal2, animal3;
object special1;

SIX_EXIT(
REGION+"i_3_5", "north",
REGION+"i_2_6", "west",
REGION+"i_4_6", "east",
REGION+"i_2_5", "northwest",
REGION+"i_2_7", "southwest",
REGION+"i_4_7", "southeast",
"In a dell", 
"In a dell. A burnet rose and a sea buckthorn are growing here. A large\nelder-grove bars the way to the south. Other dells are reachable to\nthe northwest and southwest. Dunes are to the north, west and south.\nThere are paths to the tops of the north and west dunes. Two paths are\nleading into the forest to the southeast and east. Some rabbit holes\nare around. There is an old, must-covered well here.\n"
,1 )
init() {
::init();
add_action("veg_bar","south");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"pheasant");
	PLACE_IN_THIS(animal2,REGION+"fieldmouse");
	PLACE_IN_THIS(animal3,REGION+"pheasant");
	PLACE_IN_THIS(special1,REGION+"well");
	if (arg) return;
	x = 3;
	y = 6;
	items = ({ "item", "Which item? Be more specific",
"holes", "Some rabbit holes",
"rabbit holes", "Some rabbit holes",
"burnet rose", "A burnet rose. Its tiny little yellow-white roses are starting to flower",
"sea buckthorn", "A sea buckthorn. A small thorny tree",
"large elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"elder-grove", "A rather large elder-grove. As it's not the season, no berries are on it",
"vegetation", "Thick, mixed vegetation",
"path",
"A path, or rather lack of vegetation, to the top of a dune",
"paths", "Paths onto the dunes and into the dells",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
	});
}
