/* d04 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
TWO_EXIT( REGION+"d05", "north",
REGION+"d03", "southwest",
"On top of an old dyke",
"On top of an old dyke.\n",
1 )

towadden() { return "southwest"; }

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
