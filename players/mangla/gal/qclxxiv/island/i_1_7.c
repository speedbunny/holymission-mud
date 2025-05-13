/* islgen 1.0 clean - island room 1-7 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SEVEN_EXIT(
REGION+"i_1_6", "north",
REGION+"i_0_7", "west",
REGION+"i_1_8", "south",
REGION+"i_2_7", "east",
REGION+"i_0_6", "northwest",
REGION+"i_0_8", "southwest",
REGION+"i_2_8", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the northwest, \nwest and southwest. The beach stretches forth to the north, south and \nsoutheast. A dune is to the northeast. A dell between the dunes is to\nthe east. A path leads into it.\n"
,1 )
init() {
::init();
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"seagull");
	PLACE_IN_THIS(animal2,REGION+"whiteshell");
	if (arg) return;
	x = 1;
	y = 7;
	lockno = 9;
	keyno = 1;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
