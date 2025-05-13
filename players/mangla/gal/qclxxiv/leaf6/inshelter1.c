#include "/players/qclxxiv/myroom.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (arg) return;
	items = ({
				"walls","Mouldy walls which are rotten through and through",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf6/inshelter2","south", 
"Inside a dark mouldy shelter",
"Inside a dark mouldy shelter. The musty stench of rotting wood is almost\n"+
"tangible. The place looks virtually empty.\n",0)

