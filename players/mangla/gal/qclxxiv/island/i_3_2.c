/* islgen 1.0 clean - island room 3-2 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1;

SEVEN_EXIT(
REGION+"i_3_1", "north",
REGION+"i_2_2", "west",
REGION+"i_4_2", "east",
REGION+"i_2_1", "northwest",
REGION+"i_4_1", "northeast",
REGION+"i_2_3", "southwest",
REGION+"i_4_3", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the north and \nnorthwest. The beach stretches forth to the west, southwest, east and \nnortheast. A dune is to the south. A dell between the dunes is to the \nsoutheast. A path leads into it.\n"
,1 )
init() {
::init();
add_action("veg_bar","south");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"blackshell");
	if (arg) return;
	x = 3;
	y = 2;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
