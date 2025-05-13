/* islgen 1.0 clean - island room 1-8 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2, animal3;

EIGHT_EXIT(
REGION+"i_1_7", "north",
REGION+"i_0_8", "west",
REGION+"i_1_9", "south",
REGION+"i_2_8", "east",
REGION+"i_0_7", "northwest",
REGION+"i_2_7", "northeast",
REGION+"i_0_9", "southwest",
REGION+"i_2_9", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the northwest, \nwest, southwest and south. The beach stretches forth to the north, \nsoutheast and east. A dell between the dunes is to the northeast. A path\nleads into it.\n"
,1 )

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"blackshell");
	PLACE_IN_THIS(animal2,REGION+"crab");
	PLACE_IN_THIS(animal3,REGION+"whiteshell");
	if (arg) return;
	x = 1;
	y = 8;
	items = ({ "item", "Which item? Be more specific",
"path", "A path, or rather a lack of vegetation, into a dell",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
