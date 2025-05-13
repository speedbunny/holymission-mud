/* islgen 1.0 clean - island room 1-5 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

SIX_EXIT(
REGION+"i_1_4", "north",
REGION+"i_0_5", "west",
REGION+"i_1_6", "south",
REGION+"i_2_5", "east",
REGION+"i_0_4", "northwest",
REGION+"i_0_6", "southwest",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the northwest, \nwest and southwest. The beach stretches forth to the north and south.\nDunes are to the southeast and northeast. A dell between the dunes is\nto the east. A path leads into it.\n"
,1 )
init() {
::init();
add_action("veg_bar","southeast");
add_action("veg_bar","northeast");
}

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"whiteshell");
	PLACE_IN_THIS(animal2,REGION+"brownshell");
	if (arg) return;
	x = 1;
	y = 5;
	items = ({ "item", "Which item? Be more specific",
"vegetation", "Thick, mixed vegetation",
"path", "A path, or rather a lack of vegetation, into a dell",
"dune", "A high and steep dune, covered by thick vegetation",
"dunes", "High and steep dunes, covered by thick vegetation",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
