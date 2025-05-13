/* islgen 1.0 clean - island room 2-2 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SEVEN_EXIT(
REGION+"i_2_1", "north",
REGION+"i_1_2", "west",
REGION+"i_2_3", "south",
REGION+"i_3_2", "east",
REGION+"i_1_1", "northwest",
REGION+"i_3_1", "northeast",
REGION+"i_1_3", "southwest",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the north, \nnorthwest, west and northeast. The beach stretches forth to the \nsouthwest, south and east. A dune is to the southeast.\n"
,1 )
init() {
::init();
add_action("veg_bar","southeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"seagull");
	PLACE_IN_THIS(animal2,REGION+"whiteshell");
	if (arg) return;
	x = 2;
	y = 2;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"dune", "A high and steep dune, covered by thick vegetation",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
