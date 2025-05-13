#include "/players/qclxxiv/myroom.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (arg) return;
	items = ({
			"walls","They may once have been painted, but are now peeled off",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf1/inshanty2","northwest", 
"Inside a small peeled off shanty",
"Inside a small peeled off shanty. Surrounded by bushes and without any\n"+
"windows it is dark in here. The place looks empty, though from the scarce\n"+
"dust one would guess the place was in use at least not too long ago.\n",0)

