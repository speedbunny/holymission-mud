/* islgen 1.0 clean - island room 1-4 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SEVEN_EXIT(
REGION+"i_1_3", "north",
REGION+"i_0_4", "west",
REGION+"i_1_5", "south",
REGION+"i_0_3", "northwest",
REGION+"i_2_3", "northeast",
REGION+"i_0_5", "southwest",
REGION+"i_2_5", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the northwest, \nwest and southwest. The beach stretches forth to the north, south and \nnortheast. A dune is to the east. A dell between the dunes is to the \nsoutheast. A path leads into it.\n"
,1 )
init() {
::init();
add_action("veg_bar","east");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"seagull");
	PLACE_IN_THIS(animal2,REGION+"blackshell");
	if (arg) return;
	x = 1;
	y = 4;
	lockno = 9;
	keyno = 3;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
