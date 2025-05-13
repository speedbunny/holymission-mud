#include "/players/qclxxiv/myroom.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (arg) return;
	items = ({
				"wall", "Just an ordinary mushroom wall",
				"walls", "Just ordinary mushroom walls",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf7/inmush2","east", 
"Inside a mushroom",
"Inside a mushroom. You have to bend not to bump your head. To the east the\n"+
"room continues. A tiny door can be seen in the western wall.\n",1)
