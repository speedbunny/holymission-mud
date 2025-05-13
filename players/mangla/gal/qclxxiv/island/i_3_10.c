/* islgen 1.0 clean - island room 3-10 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2, animal3;

SEVEN_EXIT(
REGION+"i_3_9", "north",
REGION+"i_2_10", "west",
REGION+"i_3_11", "south",
REGION+"i_4_10", "east",
REGION+"i_2_9", "northwest",
REGION+"i_2_11", "southwest",
REGION+"i_4_11", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the west, \nsouthwest, south and southeast. The beach stretches forth to the north, \nnorthwest and east. A dune is to the northeast.\n"
,1 )
init() {
::init();
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"whiteshell");
	PLACE_IN_THIS(animal2,REGION+"seagull");
	PLACE_IN_THIS(animal3,REGION+"redshell");
	if (arg) return;
	x = 3;
	y = 10;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"dune", "A high and steep dune, covered by thick vegetation",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
