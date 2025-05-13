/* d09 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
nr() { return 5; }
TWO_EXIT( REGION+"d08", "southwest",
REGION+"d10", "east",
"On top of an old dyke",
"On top of an old dyke. A small pole is standing here. Below you are the \n"
+"houses of the hamlet.\n",
1 )

towadden() { return "southwest"; }

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
       "pole" , "Just a small, flat-topped, pole, with the number 5 on it",
       "houses" , "small white houses",
   });
}
