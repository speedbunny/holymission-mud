/* islgen 1.0 clean - island room 2-8 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1;

SEVEN_EXIT(
REGION+"i_2_7", "north",
REGION+"i_1_8", "west",
REGION+"i_2_9", "south",
REGION+"i_3_8", "east",
REGION+"i_1_7", "northwest",
REGION+"i_1_9", "southwest",
REGION+"i_3_9", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the southwest.\nThe beach stretches forth to the northwest, west, south and southeast. A\ndune is to the northeast. Dells between the dunes are to the north and \neast. Paths lead into both of them.\n"
,1 )
init() {
::init();
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"wreckage");
	if (arg) return;
	x = 2;
	y = 8;
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
