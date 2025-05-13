/* d27 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
nr() { return 14; }
TWO_EXIT( REGION+"s1", "north",
REGION+"d26", "northeast",
"At the end of a steep dyke",
"At the end of a steep dyke. Below on one side is a rough sea, below on the\n"
+"other side is a small hamlet. The dyke stretches forth to the northeast.\n"
+"To the north is an obscure small path down to the road through the hamlet.\n"
+"Obviously this dyke is too steep to climb down from, and too high to jump off.\n"
+"A small pole is standing here.\n",
1 )

towadden() { return "north"; }

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
		"dyke", "A steep gray old dyke",
       "pole" , "Just a small, flat-topped, pole, with the number 14 on it",
   });
}

