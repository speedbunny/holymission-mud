/* in qcl castle: east hall 1 (most south) */
#include "myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

ONE_EXIT( "players/qclxxiv/entrance","west",
       	 "A small storage room.\n",
       	 "A small storage room used in the building stage of the castle.\n"+
         "Obviously the temporary walls might be taken away later. You get\n"+
		 "the feeling that a much larger room is holding this one.\n", 1)

extra_reset(arg) {
	if (arg) return;
	items = ({ ({ "hop", "hip", }), "A cool hop or a hip.\n",
			});
}
