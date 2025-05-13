/* islgen 1.0 clean - island room 2-9 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2, animal3;

EIGHT_EXIT(
REGION+"i_2_8", "north",
REGION+"i_1_9", "west",
REGION+"i_2_10", "south",
REGION+"i_3_9", "east",
REGION+"i_1_8", "northwest",
REGION+"i_3_8", "northeast",
REGION+"i_1_10", "southwest",
REGION+"i_3_10", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the west, \nsouthwest and south. The beach stretches forth to the north, northwest, \nsoutheast and east. A dell between the dunes is to the northeast. A path\nleads into it.\n"
,1 )

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"seagull");
	PLACE_IN_THIS(animal2,REGION+"blackshell");
	PLACE_IN_THIS(animal3,REGION+"wreckage");
	if (arg) return;
	x = 2;
	y = 9;
	items = ({ "item", "Which item? Be more specific",
"path", "A path, or rather a lack of vegetation, into a dell",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
