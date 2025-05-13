/* islgen 1.0 clean - island room 2-3 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"

SEVEN_EXIT(
REGION+"i_2_2", "north",
REGION+"i_1_3", "west",
REGION+"i_2_4", "south",
REGION+"i_1_2", "northwest",
REGION+"i_3_2", "northeast",
REGION+"i_1_4", "southwest",
REGION+"i_3_4", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the northwest.\nThe beach stretches forth to the north, west, southwest and northeast.\nDunes are to the south and east. There is a path to the top of the \nsouth dune. A dell between the dunes is to the southeast. A path leads\ninto it.\n"
,1 )
init() {
::init();
add_action("veg_bar","east");
}

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	x = 2;
	y = 3;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path",
"A path, or rather lack of vegetation, to the top of a dune",
"paths", "Paths onto a dune and into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
