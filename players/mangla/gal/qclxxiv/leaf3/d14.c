/* d14 */
#include "/players/qclxxiv/leaf3/dykeroom.h"
THREE_EXIT( REGION+"d13", "west",
REGION+"e07", "southwest",
REGION+"d15", "south",
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
       "street" , "Just a bumpy old bricked street",
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
