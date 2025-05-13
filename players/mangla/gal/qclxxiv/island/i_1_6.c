/* islgen 1.0 clean - island room 1-6 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2, animal3;

SEVEN_EXIT(
REGION+"i_1_5", "north",
REGION+"i_0_6", "west",
REGION+"i_1_7", "south",
REGION+"i_0_5", "northwest",
REGION+"i_2_5", "northeast",
REGION+"i_0_7", "southwest",
REGION+"i_2_7", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the northwest, \nwest and southwest. The beach stretches forth to the north and south. A\ndune is to the east. Dells between the dunes are to the southeast and \nnortheast. Paths lead into both of them.\n"
,1 )
init() {
::init();
add_action("veg_bar","east");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"crab");
	PLACE_IN_THIS(animal2,REGION+"redshell");
	PLACE_IN_THIS(animal3,REGION+"wreckage");
	if (arg) return;
	x = 1;
	y = 6;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"paths", "Paths into the dells",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"dells", "Green dells between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
