/* islgen 1.0 clean - island room 10-6 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SIX_EXIT(
REGION+"i_10_5", "north",
REGION+"i_10_7", "south",
REGION+"i_11_6", "east",
REGION+"i_11_5", "northeast",
REGION+"i_9_7", "southwest",
REGION+"i_11_7", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the southeast, \neast and northeast. The beach stretches forth to the north, southwest\nand south. A dune is to the northwest. A dell between the dunes is to\nthe west.\n"
,1 )
init() {
::init();
add_action("veg_bar","northwest");
add_action("veg_bar","west");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"crab");
	PLACE_IN_THIS(animal2,REGION+"brownshell");
	if (arg) return;
	x = 10;
	y = 6;
	lockno = 9;
	keyno = 2;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
