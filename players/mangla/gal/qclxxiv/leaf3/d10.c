/* d10 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
TWO_EXIT( REGION+"d09", "west",
REGION+"d11", "northeast",
"On top of an old dyke",
"On top of an old dyke.\n",
1 )

towadden() { return "west"; }

/*
init() {
   ::init();
   add_action( "do_get", "get" );
}
*/

extra_reset(arg) {
   if (arg) return;
    set_nodig(1);
   items = ({
		"dyke", "A steep gray old dyke",
   });
}

/*
do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
       case "street" : write("How do you plan to carry that?\n"); break;
       default: return 0;
   }
   return 1;
}
*/
