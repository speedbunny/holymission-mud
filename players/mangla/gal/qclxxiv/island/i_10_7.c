/* islgen 1.0 clean - island room 10-7 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2;

EIGHT_EXIT(
REGION+"i_10_6", "north",
REGION+"i_9_7", "west",
REGION+"i_10_8", "south",
REGION+"i_11_7", "east",
REGION+"i_9_6", "northwest",
REGION+"i_11_6", "northeast",
REGION+"i_9_8", "southwest",
REGION+"i_11_8", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the south, \nsoutheast, east and northeast. The beach stretches forth to the north, \nwest and southwest. A dell between the dunes is to the northwest. A path\nleads into it.\n"
,1 )

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"blackshell");
	PLACE_IN_THIS(animal2,REGION+"seagull");
	if (arg) return;
	x = 10;
	y = 7;
	items = ({ "item", "Which item? Be more specific",
"path", "A path, or rather a lack of vegetation, into a dell",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
