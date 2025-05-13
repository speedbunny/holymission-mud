/* d05 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
nr() { return 3; }
TWO_EXIT( REGION+"d04", "south",
REGION+"d06", "northeast",
"On top of an old dyke",
"On top of an old dyke. A small pole is standing here. Below you are the \n"
+"houses of the hamlet.\n",
1 )

towadden() { return "south"; }

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
       "houses" , "small white houses",
       "pole" , "Just a small, flat-topped, pole, with the number 3 on it",
   });
}

