/* islgen 1.0 clean - island room 1-3 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2, animal3, animal4;

SEVEN_EXIT(
REGION+"i_1_2", "north",
REGION+"i_0_3", "west",
REGION+"i_1_4", "south",
REGION+"i_2_3", "east",
REGION+"i_0_2", "northwest",
REGION+"i_2_2", "northeast",
REGION+"i_0_4", "southwest",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the north, \nnorthwest, west and southwest. The beach stretches forth to the south, \neast and northeast. A dune is to the southeast.\n"
,1 )
init() {
::init();
add_action("veg_bar","southeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"redshell");
	PLACE_IN_THIS(animal2,REGION+"crab");
	PLACE_IN_THIS(animal3,REGION+"whiteshell");
	PLACE_IN_THIS(animal4,REGION+"wreckage");
	if (arg) return;
	x = 1;
	y = 3;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"dune", "A high and steep dune, covered by thick vegetation",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
