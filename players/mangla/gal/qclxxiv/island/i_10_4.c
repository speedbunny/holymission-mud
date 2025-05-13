/* islgen 1.0 clean - island room 10-4 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SEVEN_EXIT(
REGION+"i_10_3", "north",
REGION+"i_9_4", "west",
REGION+"i_10_5", "south",
REGION+"i_11_4", "east",
REGION+"i_9_3", "northwest",
REGION+"i_11_3", "northeast",
REGION+"i_11_5", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the southeast, \neast and northeast. The beach stretches forth to the north, northwest\nand south. A dune is to the southwest. A dell between the dunes is to\nthe west. A path leads into it.\n"
,1 )
init() {
::init();
add_action("veg_bar","southwest");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"wreckage");
	PLACE_IN_THIS(animal2,REGION+"crab");
	if (arg) return;
	x = 10;
	y = 4;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
