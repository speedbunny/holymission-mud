#include "/players/qclxxiv/myroom.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	if (arg) return;
	items = ({
				"walls","The walls are as dirty as anything around here",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf6/inshackle2","north", 
"Inside a dingy dark shackle",
"Inside a dingy dark shackle. This place stinks like a cesspit. You wonder\n"+
"what has been stored here. Right now the place looks empty.\n",0)

