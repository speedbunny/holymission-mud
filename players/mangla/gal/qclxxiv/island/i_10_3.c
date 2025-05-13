/* islgen 1.0 clean - island room 10-3 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/beach";
#include "roommacros.h"
object animal1, animal2, animal3;

EIGHT_EXIT(
REGION+"i_10_2", "north",
REGION+"i_9_3", "west",
REGION+"i_10_4", "south",
REGION+"i_11_3", "east",
REGION+"i_9_2", "northwest",
REGION+"i_11_2", "northeast",
REGION+"i_9_4", "southwest",
REGION+"i_11_4", "southeast",
"On a beach", 
"On a beach. The breakers, one mass of whirl pools, is to the north, \nsoutheast, east and northeast. The beach stretches forth to the \nnorthwest, west and south. A dell between the dunes is to the southwest.\nA path leads into it.\n"
,1 )

extra_reset(arg) {
	::extra_reset(arg);
	PLACE_IN_THIS(animal1,REGION+"blackshell");
	PLACE_IN_THIS(animal2,REGION+"whiteshell");
	PLACE_IN_THIS(animal3,REGION+"seagull");
	if (arg) return;
	x = 10;
	y = 3;
	items = ({ "item", "Which item? Be more specific",
"path", "A path, or rather a lack of vegetation, into a dell",
"dell", "A green dell between the dunes",
"beach", "A clean and rather broad beach, and the breakers thereafter",
	});
}
