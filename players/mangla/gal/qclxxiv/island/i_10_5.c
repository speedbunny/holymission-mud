/* islgen 1.0 clean - island room 10-5 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SEVEN_EXIT(
REGION+"i_10_4", "north",
REGION+"i_10_6", "south",
REGION+"i_11_5", "east",
REGION+"i_9_4", "northwest",
REGION+"i_11_4", "northeast",
REGION+"i_9_6", "southwest",
REGION+"i_11_6", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the southeast, \neast and northeast. The beach stretches forth to the north and south. A\ndune is to the west. Dells between the dunes are to the northwest and \nsouthwest. Paths lead into both of them.\n"
,1 )
init() {
::init();
add_action("veg_bar","west");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"whiteshell");
	PLACE_IN_THIS(animal2,REGION+"seagull");
	if (arg) return;
	x = 10;
	y = 5;
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
