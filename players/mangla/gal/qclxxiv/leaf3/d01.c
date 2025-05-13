/* d01 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
nr() { return 1; }
TWO_EXIT( REGION+"s1", "east",
REGION+"d02", "northeast",
"At the end of a steep dyke",
"At the end of a steep dyke. Below on one side is a rough sea, below on the\n"
+"other side is a small hamlet. The dyke stretches forth to the northeast.\n"
+"To the east is an obscure small path down to the road through the hamlet.\n"
+"Obviously this dyke is too steep to climb down from, and too high to jump off.\n"
+"A small pole is standing here.\n",
1 )

towadden() { return "east"; }

init() {
   ::init();
   add_action( "do_get", "get" );
   add_action( "touch", "touch");
}

extra_reset(arg) {
   loot = 0;
   if (arg) return;
    set_nodig(1);
   items = ({
       "pole" , "Just a small, flat-topped, pole, with the number 1 on it",
		"dyke", "A steep gray old dyke",
   });
}

